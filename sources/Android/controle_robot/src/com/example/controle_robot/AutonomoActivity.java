package com.example.controle_robot;

import android.os.AsyncTask;
import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import android.view.View.OnClickListener;
import android.util.*;

import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;

import com.example.controle_robot.MainActivity;

//mensagem enviada pela Activity1 no formato <Name, Address>

public class AutonomoActivity extends Activity {

    public final String categoria = "debug";
    public AsyncTaskRunner runner = new AsyncTaskRunner();
    char metodo = 0; // 0: metodo de envio assincrono por socket UDP

    // 1: metodo de envio assincrono por socket TCP

    /**
     * @author Prabu Private class which runs the long operation. ( Sleeping for
     *         some time )
     */

    /* tarefa assincrona para executar o envio de pacotes por socket UDP */
    private class AsyncTaskRunner extends AsyncTask<String, Void, Void> {

	private static final int SERVER_PORT = 6000;
	private static final String SERVER_IP = "10.0.1.102"; // ip do
							      // dispositivo
							      // android image
							      // processing
	DatagramSocket ds = null;
	private Socket socket;

	protected Void doInBackground(String... params) {

	    try {
		if (metodo == 0) {
		    ds = new DatagramSocket();
		    InetAddress serverAddr = InetAddress.getByName(SERVER_IP);
		    DatagramPacket dp;
		    //char c = params[0].charAt(0);
		    //String udpMsg = c+"";
		    String udpMsg = params[0];
		    dp = new DatagramPacket(udpMsg.getBytes(), udpMsg.length(),
			    serverAddr, SERVER_PORT);
		    ds.send(dp);
		    Log.d(categoria, "msg enviada: " + udpMsg);
		} else {
		    InetAddress serverAddr = InetAddress.getByName(SERVER_IP);
		    socket = new Socket(serverAddr, SERVER_PORT);
		    PrintWriter out = new PrintWriter(new BufferedWriter(
			    new OutputStreamWriter(socket.getOutputStream())),
			    true);
		    //char c = params[0].charAt(0);
		    //out.println(c);
		    out.println(params[0]);
		    Log.d(categoria, "msg enviada: " + params[0]);
		    out.flush();
		    out.close();
		    socket.close(); // closing the connection
		}
	    } catch (Exception e) {
		e.printStackTrace();
		e.getMessage();
	    }
	    return null;
	}

    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
	super.onCreate(savedInstanceState);
	setContentView(R.layout.autonomo_activity);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
	// Inflate the menu; this adds items to the action bar if it is present.
	getMenuInflater().inflate(R.menu.main, menu);
	Button button_exit = (Button) findViewById(R.id.button_back_main);
	Button button_autonomous = (Button) findViewById(R.id.button_autonomous);

	button_autonomous.setOnClickListener(new OnClickListener() {
	    @Override
	    public void onClick(View view) {
		Toast.makeText(AutonomoActivity.this, "Autonomous Mode",
			Toast.LENGTH_SHORT).show();
		try {
		    runner = new AsyncTaskRunner();
		    runner.execute("autonomous");
		    Log.d(categoria, "AM apertado");

		} catch (Exception e) {
		    e.printStackTrace();
		}
	    }
	});

	button_exit.setOnClickListener(new OnClickListener() {
	    @Override
	    public void onClick(View view) {
		Toast.makeText(AutonomoActivity.this, "exit",
			Toast.LENGTH_SHORT).show();
		try {
		    runner = new AsyncTaskRunner();
		    runner.execute("exit");
		    Log.d(categoria, "exit apertado");
		    Log.d(categoria, "saindo do modo autonomo");
		    Log.d(categoria, "socket fechado");
		} catch (Exception e) {
		    e.printStackTrace();
		}
		volta_para_main(view);
	    }
	});

	return true;
    }

    public void volta_para_main(View view) {
	Intent intent = new Intent(this, MainActivity.class);
	// Volta para o menu.
	startActivity(intent);
	Log.d(categoria, "voltando para main");
    }

}
