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

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

import com.example.controle_robot.MainActivity;

//mensagem enviada pela Activity1 no formato <Name, Address>

public class ManualActivity extends Activity {

    public final String categoria = "debug";
    public AsyncTaskRunner runner = new AsyncTaskRunner();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
	super.onCreate(savedInstanceState);
	setContentView(R.layout.manual_actvitity);

    }

    /**
     * @author Prabu Private class which runs the long operation. ( Sleeping for
     *         some time )
     */
    /* tarefa assincrona para executar o envio de pacotes por socket UDP */
    private class AsyncTaskRunner extends AsyncTask<String, Void, Void> {

	private static final int SERVER_PORT = 80;
	private static final String SERVER_IP = "10.0.1.101";
	DatagramSocket ds = null;
	
	protected Void doInBackground(String... params) {

	    try {
	        ds = new DatagramSocket();
	        InetAddress serverAddr = InetAddress.getByName(SERVER_IP);
	        DatagramPacket dp;
	        char c = params[0].charAt(0);
	        String udpMsg = c+"";
	        dp = new DatagramPacket(udpMsg.getBytes(), udpMsg.length(), serverAddr, SERVER_PORT);
	        ds.send(dp);
		Log.d(categoria, "msg enviada: "+udpMsg);


	    } catch (Exception e) {
		e.printStackTrace();
		e.getMessage();
	    }
	    return null;
	}

    }
    
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
	// Inflate the menu; this adds items to the action bar if it is present.
	getMenuInflater().inflate(R.menu.main, menu);
	final Button button_up = (Button) findViewById(R.id.up);
	final Button button_down = (Button) findViewById(R.id.down);
	final Button button_left = (Button) findViewById(R.id.left);
	final Button button_right = (Button) findViewById(R.id.right);
	final Button button_exit = (Button) findViewById(R.id.button_back_main);

	
	button_up.setOnClickListener(new OnClickListener() {
	    @Override
	    public void onClick(View view) {
		Toast.makeText(ManualActivity.this, "up", Toast.LENGTH_SHORT)
		.show();

		try {
		    runner = new AsyncTaskRunner();
		    runner.execute("up");
		    Log.d(categoria, "up apertado");

		} catch (Exception e) {
		    e.printStackTrace();
		}
	    }
	});

	button_down.setOnClickListener(new OnClickListener() {
	    @Override
	    public void onClick(View view) {
		Toast.makeText(ManualActivity.this, "down", Toast.LENGTH_SHORT)
		.show();
		try {
		    runner = new AsyncTaskRunner();
		    runner.execute("down");
		    Log.d(categoria, "down apertado");

		} catch (Exception e) {
		    e.printStackTrace();
		}
	    }
	});

	button_left.setOnClickListener(new OnClickListener() {
	    @Override
	    public void onClick(View view) {
		Toast.makeText(ManualActivity.this, "left", Toast.LENGTH_SHORT)
		.show();
		try {
		    runner = new AsyncTaskRunner();
		    runner.execute("left");
		    Log.d(categoria, "left apertado");
		} catch (Exception e) {
		    e.printStackTrace();
		}
	    }
	});

	button_right.setOnClickListener(new OnClickListener() {
	    @Override
	    public void onClick(View view) {
		Toast.makeText(ManualActivity.this, "right", Toast.LENGTH_SHORT)
		.show();
		try {
		    runner = new AsyncTaskRunner();
		    runner.execute("right");
		    Log.d(categoria, "right apertado");
		} catch (Exception e) {
		    e.printStackTrace();
		}
	    }
	});

	button_exit.setOnClickListener(new OnClickListener() {
	    @Override
	    public void onClick(View view) {
		Toast.makeText(ManualActivity.this, "exit", Toast.LENGTH_SHORT)
		.show();
		try {
		    runner = new AsyncTaskRunner();
		    runner.execute("exit");
		    Log.d(categoria, "exit apertado");
		    Log.d(categoria, "saindo do modo manual");
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
