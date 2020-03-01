package com.mycompany.myapp;

import android.app.*;
import android.content.*;
import android.net.*;
import android.os.*;
import android.view.*;
import android.widget.*;

public class MainActivity extends Activity 
{
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
		if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.KITKAT) 
			{              
			    Window window = getWindow();                            
				window.setFlags(WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS,WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS);
				}
        setContentView(R.layout.main);
    }
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu)
	{
		//菜单
		MenuInflater inflater=getMenuInflater();
		inflater.inflate(R.menu.main_menu,menu);
		return super.onCreateOptionsMenu(menu);
	}
	public void onButtonClickGram(View g)
	{
		//响应c++语法按钮跳转页面
		Intent intentGram= new Intent();
		//参数1：当前页面。参数2：目的跳转页面。
		intentGram.setClass(MainActivity.this,grammer.class);
		startActivity(intentGram);
		//MainActivity.this.finish();
	}
	public void onButtonClickStru(View s)
	{
		//响应c++语法按钮跳转页面
		Intent intentStru= new Intent();
		//参数1：当前页面。参数2：目的跳转页面。
		intentStru.setClass(MainActivity.this,structure.class);
		startActivity(intentStru);
		//MainActivity.this.finish();
	}
	public void onButtonClickAlgo(View a)
	{
		//响应数据结构和算法按钮跳转页面
		Intent intentAlgo= new Intent();
		intentAlgo.setClass(MainActivity.this,algorithm.class);
		startActivity(intentAlgo);
	}
	public void onButtonClickProg(View p)
	{
		//响应程序例子按钮跳转页面
		Intent intentProg= new Intent();
		intentProg.setClass(MainActivity.this,program.class);
		startActivity(intentProg);
	}
	public void onButtonClickQues(View q)
	{
		//响应问题按钮跳转页面
		Intent intentQues= new Intent();
		intentQues.setClass(MainActivity.this,question.class);
		startActivity(intentQues);
	}
	@Override
	public boolean onOptionsItemSelected(MenuItem item)
	{
		//菜单选项
		switch(item.getItemId())
		{
			case R.id.connect:
			Toast.makeText(this,"联系作者中...",Toast.LENGTH_SHORT).show();
			
				String url11 = "mqqwpa://im/chat?chat_type=wpa&uin=1105403369&version=1";
				startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse(url11)));
				return true;
			case R.id.update:
				Toast.makeText(this,"版本更新中...",Toast.LENGTH_SHORT).show();
				return true;
					
		}
		return super.onOptionsItemSelected(item);
	}
	
}
