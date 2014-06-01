package com.example.controle_robot;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.View;

import com.example.controle_robot.ManualActivity;

public class MainActivity extends Activity {
    public final String categoria = "debug";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
	super.onCreate(savedInstanceState);
	setContentView(R.layout.tela_inicial);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
	// Inflate the menu; this adds items to the action bar if it is present.
	getMenuInflater().inflate(R.menu.main, menu);
	return true;
    }

    // actions which refers to manual button
    public void go_manual_button(View view) {

	Intent intent = new Intent(this, ManualActivity.class);
	// Inicia a nova tela.
	startActivity(intent);
    }

    // actions which refers to autonomo button
    public void go_autonomo_button(View view) {

	Intent intent = new Intent(this, AutonomoActivity.class);
	// Inicia a nova tela.
	startActivity(intent);
    }

}
