package org.opencv.samples.imagemanipulations;

/********* java imports ****************/
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;





/********* opencv imports ****************/
import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;
import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.core.MatOfPoint;
import org.opencv.core.Point;
import org.opencv.core.Rect;
import org.opencv.core.Scalar;
import org.opencv.core.Size;
import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewListener;
import org.opencv.imgproc.Imgproc;





/********* android imports ****************/
import android.app.Activity;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.PowerManager;
import android.text.TextUtils;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.WindowManager;
import android.widget.Toast;
import android.content.Context;

public class ImageManipulationsActivity extends Activity implements
CvCameraViewListener {

    /* OpenCV Variables */
    private static final String  TAG            = "OCVSample::Activity";
    private CameraBridgeViewBase mOpenCvCameraView;
    private Mat                  mRgba;
    private Mat                  mRgbaInnerWindow;

    /* Image Processing variables */
    public String                coordx;
    public String                coordy;
    public String                coords;
    public int                   coordX_int     = 0;
    public int                   coordY_int     = 0;

    /* Wakelock variables */
    public PowerManager.WakeLock wl;

    /* Debug Variables */
    private static final boolean wifi_on        = true;
    String                       answer;
    public final String          categoria      = "debug";
    public AsyncTaskRunner       runner         = new AsyncTaskRunner();
    public AsyncTaskRunner       runnerReceiver = new AsyncTaskRunner();
    public int                   flag_autonomo  = 0;
    public int                   frameDivider   = 0;

    /********************** Connect on Arduino Server to send UDP messages *******************************/
    /*
     * @author Prabu Private class which runs the long operation. ( Sleeping for
     * some time )
     */

    /*
     * tarefa assincrona para executar o envio de pacotes por socket UDP para o
     * Arduino
     */
    private class AsyncTaskRunner extends AsyncTask<String, Void, Void> {

        private static final int    ARDUINO_PORT = 80;
        private static final String ARDUINO_IP   = "10.0.1.101";
        DatagramSocket              ds           = null;

        protected Void doInBackground(String... params) {

            try {
                ds = new DatagramSocket();
                InetAddress serverAddr = InetAddress.getByName(ARDUINO_IP);
                DatagramPacket dp;
                char c = params[0].charAt(0);
                String udpMsg = c + "";
                dp = new DatagramPacket(udpMsg.getBytes(), udpMsg.length(),
                        serverAddr, ARDUINO_PORT);
                ds.send(dp);

            }
            catch (Exception e) {
                e.printStackTrace();
                e.getMessage();
            }
            return null;
        }
    }

    /********************** Application Server socket *******************************/
    /*
     * Control device connects with this phone IP in order to change the
     * flag_autonomo state and turn on/off the image processing instructions
     */

    public static final int APP_PORT = 6000;

    class ReceiverThread extends Thread {
        DatagramSocket  socket;

        private boolean stopped = false;

        public ReceiverThread(DatagramSocket ds) throws SocketException {
            this.socket = ds;
        }

        public void halt() {
            this.stopped = true;
        }

        public void run() {
            byte[] buffer = new byte[50];
            while (true) {
                if (stopped) return;

                DatagramPacket dp = new DatagramPacket(buffer, buffer.length);
                try {
                    socket.receive(dp);
                    String rcv = null;
                    rcv = new String(buffer, 0, dp.getLength());

                    int a_comparacao = rcv.compareTo("autonomous");
                    int e_comparacao = rcv.compareTo("exit");
                    if (a_comparacao == 0) {
                        flag_autonomo = 1;
                        mOpenCvCameraView.enableView();
                    }
                    if (e_comparacao == 0) {
                        flag_autonomo = 0;
                        mOpenCvCameraView.disableView();             
                    }
                    Log.d(categoria, "recebi:" + rcv);

                    Log.d(categoria, "flag autonomo: " + flag_autonomo);
                    Thread.yield();
                }
                catch (IOException ex) {
                    System.err.println(ex);
                }
            }
        }
    }

    /************************************************
     * /*********************** Wakelock Handler
     ********************************/
    public void config_Wakelock() {
        PowerManager pm = (PowerManager) getSystemService(Context.POWER_SERVICE);
        wl = pm.newWakeLock(PowerManager.SCREEN_DIM_WAKE_LOCK, "My Tag");
        wl.acquire();
    }

    public static String getCurrentSsid(Context context) {
        String ssid = null;
        ConnectivityManager connManager = (ConnectivityManager) context.getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo networkInfo = connManager.getNetworkInfo(ConnectivityManager.TYPE_WIFI);
        if (networkInfo.isConnected()) {
            final WifiManager wifiManager = (WifiManager) context.getSystemService(Context.WIFI_SERVICE);
            final WifiInfo connectionInfo = wifiManager.getConnectionInfo();
            if (connectionInfo != null && !TextUtils.isEmpty(connectionInfo.getSSID())) {
                ssid = connectionInfo.getSSID();
            }
        }
        return ssid;
    }

    /*********************** Android Handlers ********************************/
    @Override
    public void onCreate(Bundle savedInstanceState) {
        Log.i(TAG, "called onCreate");
        super.onCreate(savedInstanceState);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        // test for internet connection
        ConnectivityManager cm = (ConnectivityManager) getApplicationContext()
                .getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo activeNetwork = cm.getActiveNetworkInfo();
        if (activeNetwork != null) {
            if (activeNetwork.getType() == ConnectivityManager.TYPE_WIFI) {
                answer = "You are connected to a WiFi Network";
                Log.d(categoria, "estou numa rede wifi");
                String connectedSSID = getCurrentSsid(this);
                Log.d(categoria, "ssid conectado: "+connectedSSID);
                answer = "You are connected to a WiFi Network SSID: "+connectedSSID;
                int w_comparacao = connectedSSID.compareTo("vs_robot");

                if (w_comparacao == 0) {
                    config_Wakelock();
                    Log.d(categoria, "wakelock configurado");
                    setContentView(R.layout.image_manipulations_surface_view);
                    DatagramSocket socket = null;
                    try {
                        socket = new DatagramSocket(APP_PORT);
                    }
                    catch (SocketException e1) {
                        e1.printStackTrace();
                    }

                    Thread receiver = null;
                    try {
                        receiver = new ReceiverThread(socket);
                    }
                    catch (SocketException e) {
                        e.printStackTrace();
                    }
                    receiver.start();
                    mOpenCvCameraView = (CameraBridgeViewBase) findViewById(R.id.image_manipulations_activity_surface_view);
                    mOpenCvCameraView.setCvCameraViewListener(this);
                } else  finish();
            }
        }
        else {
            // should have show an error
            answer = "No internet Connectivity";
            Log.d(categoria, answer);
        }
        Toast.makeText(getApplicationContext(), answer, Toast.LENGTH_LONG)
        .show();
    }

    private BaseLoaderCallback mLoaderCallback = new BaseLoaderCallback(this) {
        @Override
        public void onManagerConnected(
                int status) {
            switch (status) {
                case LoaderCallbackInterface.SUCCESS: {
                    Log.i(TAG,
                            "OpenCV loaded successfully");
                    //mOpenCvCameraView.enableView();
                }
                break;
                default: {
                    super.onManagerConnected(status);
                }
                break;
            }
        }
    };

    @Override
    protected void onStop() {
        super.onStop();
    }

    @Override
    public void onPause() {
        if (mOpenCvCameraView != null) mOpenCvCameraView.disableView();
        super.onPause();
        wl.release();
    }

    @Override
    public void onResume() {
        super.onResume();
        OpenCVLoader.initAsync(OpenCVLoader.OPENCV_VERSION_2_4_3, this,
                mLoaderCallback);
        wl.acquire();

    }

    public void onDestroy() {   
        if (mOpenCvCameraView != null) mOpenCvCameraView.disableView();
        //android.os.Process.killProcess(android.os.Process.myPid());
        super.onDestroy();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Log.i(TAG, "called onCreateOptionsMenu");
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Log.i(TAG, "called onOptionsItemSelected; selected item: " + item);
        return true;
    }

    /*********************** OpenCV ********************************/

    public ImageManipulationsActivity() {
        // Log.i(TAG, "Instantiated new " + this.getClass());
    }

    public void onCameraViewStarted(int width, int height) {
        mRgba = new Mat();
    }

    /*********** get bounding box center point ******************/
    public static void getCenterPoint(Point tl, Point br, Point dst) {
        dst.x = (tl.x + br.x) / 2;
        dst.y = (tl.y + br.y) / 2;
    }

    /* return the biggest countor found while processing the image */
    public static int getBiggestContourIndex(List<MatOfPoint> contours) {
        double maxArea = 0;
        Iterator<MatOfPoint> each = contours.iterator();
        int j = 0;
        int k = -1;
        while (each.hasNext()) {
            MatOfPoint wrapper = each.next();
            double area = Imgproc.contourArea(wrapper);
            if (area > maxArea && area > 2000) { // area size filter
                maxArea = area;
                k = j;
            }
            j++;
        }
        Log.d("info", "maxArea= " + maxArea);
        Log.d("info", "k value= " + k);
        return k;
    }

    /* wraps object inside bounding box */
    public static Rect setContourRect(List<MatOfPoint> contours, int k) {
        Rect boundRect = new Rect();
        Iterator<MatOfPoint> each = contours.iterator();
        int j = 0;
        while (each.hasNext()) {
            MatOfPoint wrapper = each.next();
            if (j == k) {
                return Imgproc.boundingRect(wrapper);
            }
            j++;
        }
        return boundRect;
    }

    public void onCameraViewStopped() {
        // Explicitly deallocate Mats
        if (mRgbaInnerWindow != null) mRgbaInnerWindow.release();
        if (mRgba != null) mRgba.release();

        mRgba = null;
        mRgbaInnerWindow = null;
    }

    public Mat onCameraFrame(Mat inputFrame) {

        Log.d(categoria, "autonomo = 0");

        inputFrame.copyTo(mRgba);

        //frameDivider its a 5th order decimation frame filter
        if (flag_autonomo == 1) {
            frameDivider++;
            Log.d(categoria, "autonomo = 1");
            if (frameDivider == 5) {
                Log.d(categoria, "frameDivider =" + frameDivider);
                Mat HSV = new Mat();

                Imgproc.cvtColor(mRgba, HSV, Imgproc.COLOR_BGR2HSV);

                // creates an intermediate matrix
                Mat teste = new Mat();

                Core.inRange(HSV, new Scalar(127, 100, 100), new Scalar(140,
                        255, 255), teste);

                // smoothing contours for better detection
                Imgproc.GaussianBlur(teste, teste, new Size(3, 3), 2.0, 2.0);

                teste.copyTo(mRgba);

                List<MatOfPoint> contours = new ArrayList<MatOfPoint>();
                Mat hierarchy = new Mat();

                Imgproc.findContours(teste, contours, hierarchy,
                        Imgproc.RETR_EXTERNAL, Imgproc.CHAIN_APPROX_SIMPLE);

                if (contours.size() > 0) {
                    int k = getBiggestContourIndex(contours);
                    // writes the bounding box in the biggest contour found in
                    // the frame
                    if (k != -1) {
                        Rect boundRect = setContourRect(contours, k);

                        Point center = new Point();
                        getCenterPoint(boundRect.tl(), boundRect.br(), center);
                        Core.rectangle(mRgba, boundRect.tl(), boundRect.br(),
                                new Scalar(255, 255, 0), 2, 8, 0);

                        // marks a circle in the middle of bounding box found
                        Core.circle(mRgba, new Point(
                                (boundRect.x + boundRect.width / 2),
                                (boundRect.y + boundRect.height / 2)), 3,
                                new Scalar(255, 0, 0), -3, 8, 0);

                        coordx = "";
                        coordx = "" + (boundRect.x + boundRect.width / 2);
                        coordX_int = (boundRect.x + boundRect.width / 2);
                        coordy = "" + (boundRect.y + boundRect.height / 2);
                        coordY_int = (boundRect.y + boundRect.height / 2);
                        coords = "X:" + coordx + "  Y:" + coordy;

                        Core.putText(mRgba, coords, new Point(10, 100), 3, 1,
                                new Scalar(255, 0, 0, 255), 3);

                        // states of movement
                        if (coordX_int >= 160 && coordX_int <= 320) {
                            Core.putText(mRgba, "FORWARD", new Point(30, 300),
                                    3, 1, new Scalar(255, 0, 0, 255), 3);
                            coords = "up";
                        }
                        if (coordX_int > 0 && coordX_int < 160) {
                            Core.putText(mRgba, "LEFT", new Point(30, 300), 3,
                                    1, new Scalar(255, 0, 0, 255), 3);
                            coords = "left";
                        }
                        if (coordX_int > 320 && coordX_int <= 480) {
                            Core.putText(mRgba, "RIGHT", new Point(30, 300), 3,
                                    1, new Scalar(255, 0, 0, 255), 3);
                            coords = "right";
                        }

                        runner = new AsyncTaskRunner();
                        runner.execute(coords);

                    }
                    else {
                        Core.putText(mRgba, "null", new Point(10, 100), 3, 1,
                                new Scalar(255, 0, 0, 255), 3);
                        coords = "null";

                        runner = new AsyncTaskRunner();
                        runner.execute(coords);

                    }

                }
                else {
                    Core.putText(mRgba, "null", new Point(10, 100), 3, 1,
                            new Scalar(255, 0, 0, 255), 3);
                    coords = "null";
                    if (wifi_on) {
                        runner = new AsyncTaskRunner();
                        runner.execute(coords);
                    }
                }

                contours.clear();
                HSV.release();
                teste.release();
                hierarchy.release();
                frameDivider = 0;
            }
            Core.putText(mRgba, "AUTONOMOUS", new Point(10, 100), 3, 1,
                    new Scalar(255, 0, 0, 255), 3);
            return mRgba;

        }
        // //while flag_autonomo = 0 it just returns the raw acquired frame
        else return mRgba;
    }
}
