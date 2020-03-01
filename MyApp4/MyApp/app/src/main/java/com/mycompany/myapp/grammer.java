package com.mycompany.myapp;


import android.app.*;
import android.content.*;
import android.os.*;
import android.text.method.*;
import android.view.*;
import android.view.View.*;
import android.widget.*;

public class grammer extends Activity 
{
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.grammer);
		
		
		/*枚举*/
		
		//复制按钮
		TextView mCopy = (TextView) findViewById(R.id.btn_cmeiju);
		//被复制的内容
		final TextView mContent = (TextView) findViewById(R.id.et_meiju);
		mContent.setMovementMethod(ScrollingMovementMethod.getInstance());
		mContent.setOnTouchListener(new View.OnTouchListener() {
                @Override
                public boolean onTouch(View v, MotionEvent event) {
                    if (event.getAction() == MotionEvent.ACTION_DOWN) {
                        // 通知ScrollView控件不要干扰
                        v.getParent().requestDisallowInterceptTouchEvent(true);
                    }
                    if (event.getAction() == MotionEvent.ACTION_MOVE) {
                        // 通知ScrollView控件不要干扰
                        v.getParent().requestDisallowInterceptTouchEvent(true);
                    }
                    if (event.getAction() == MotionEvent.ACTION_UP) {
                        v.getParent().requestDisallowInterceptTouchEvent(false);
                    }
                    return false;
                }

            });
		mCopy.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View view) {
					//获取剪贴板，并把内容设置在剪切板
					ClipboardManager cbm=(ClipboardManager)getSystemService(Context.CLIPBOARD_SERVICE);
					cbm.setText(mContent.getText().toString());
					Toast.makeText(grammer.this,"已经复制",Toast.LENGTH_LONG).show();
				}
			});
			
			

		/*数组*/

		//复制按钮
		TextView mCopy1 = (TextView) findViewById(R.id.btn_cshuzu);
		//被复制的内容
		final TextView mContent1 = (TextView) findViewById(R.id.et_shuzu);
		mContent1.setMovementMethod(ScrollingMovementMethod.getInstance());
		mContent1.setOnTouchListener(new View.OnTouchListener() {
                @Override
                public boolean onTouch(View v, MotionEvent event) {
                    if (event.getAction() == MotionEvent.ACTION_DOWN) {
                        // 通知ScrollView控件不要干扰
                        v.getParent().requestDisallowInterceptTouchEvent(true);
                    }
                    if (event.getAction() == MotionEvent.ACTION_MOVE) {
                        // 通知ScrollView控件不要干扰
                        v.getParent().requestDisallowInterceptTouchEvent(true);
                    }
                    if (event.getAction() == MotionEvent.ACTION_UP) {
                        v.getParent().requestDisallowInterceptTouchEvent(false);
                    }
                    return false;
                }

            });
		mCopy1.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View view) {
					//获取剪贴板，并把内容设置在剪切板
					ClipboardManager cbm=(ClipboardManager)getSystemService(Context.CLIPBOARD_SERVICE);
					cbm.setText(mContent.getText().toString());
					Toast.makeText(grammer.this,"已经复制",Toast.LENGTH_LONG).show();
				}
			});
			
			
			

		/*引用*/

		//复制按钮
		TextView mCopy2 = (TextView) findViewById(R.id.btn_cyinyong);
		//被复制的内容
		final TextView mContent2 = (TextView) findViewById(R.id.et_yinyong);
		mContent2.setMovementMethod(ScrollingMovementMethod.getInstance());
		mContent2.setOnTouchListener(new View.OnTouchListener() {
                @Override
                public boolean onTouch(View v, MotionEvent event) {
                    if (event.getAction() == MotionEvent.ACTION_DOWN) {
                        // 通知ScrollView控件不要干扰
                        v.getParent().requestDisallowInterceptTouchEvent(true);
                    }
                    if (event.getAction() == MotionEvent.ACTION_MOVE) {
                        // 通知ScrollView控件不要干扰
                        v.getParent().requestDisallowInterceptTouchEvent(true);
                    }
                    if (event.getAction() == MotionEvent.ACTION_UP) {
                        v.getParent().requestDisallowInterceptTouchEvent(false);
                    }
                    return false;
                }

            });
		mCopy2.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View view) {
					//获取剪贴板，并把内容设置在剪切板
					ClipboardManager cbm=(ClipboardManager)getSystemService(Context.CLIPBOARD_SERVICE);
					cbm.setText(mContent.getText().toString());
					Toast.makeText(grammer.this,"已经复制",Toast.LENGTH_LONG).show();
				}
			});
			
			
		/*临时对象*/
		
		TextView mCopy3 = (TextView) findViewById(R.id.btn_clinshiduixiang);
		//被复制的内容
		final TextView mContent3 = (TextView) findViewById(R.id.et_linshiduixiang);
		mContent3.setMovementMethod(ScrollingMovementMethod.getInstance());
		mContent3.setOnTouchListener(new View.OnTouchListener() {
                @Override
                public boolean onTouch(View v, MotionEvent event) {
                    if (event.getAction() == MotionEvent.ACTION_DOWN) {
                        // 通知ScrollView控件不要干扰
                        v.getParent().requestDisallowInterceptTouchEvent(true);
                    }
                    if (event.getAction() == MotionEvent.ACTION_MOVE) {
                        // 通知ScrollView控件不要干扰
                        v.getParent().requestDisallowInterceptTouchEvent(true);
                    }
                    if (event.getAction() == MotionEvent.ACTION_UP) {
                        v.getParent().requestDisallowInterceptTouchEvent(false);
                    }
                    return false;
                }

            });
		mCopy3.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View view) {
					//获取剪贴板，并把内容设置在剪切板
					ClipboardManager cbm=(ClipboardManager)getSystemService(Context.CLIPBOARD_SERVICE);
					cbm.setText(mContent.getText().toString());
					Toast.makeText(grammer.this,"已经复制",Toast.LENGTH_LONG).show();
				}
			});
    }
}
