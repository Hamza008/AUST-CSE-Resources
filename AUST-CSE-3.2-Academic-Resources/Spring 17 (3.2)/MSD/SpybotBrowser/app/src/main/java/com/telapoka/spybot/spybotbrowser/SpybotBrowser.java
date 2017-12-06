package com.telapoka.spybot.spybotbrowser;

import android.app.Activity;
import android.os.Build;
import android.support.annotation.RequiresApi;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.EditText;

public class SpybotBrowser extends Activity implements View.OnClickListener{

    private Button go;
    private EditText input;
    String texts;
    WebView webView;
    @RequiresApi(api = Build.VERSION_CODES.CUPCAKE)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_spybot_browser);
        webView = (WebView) findViewById(R.id.webView);
        go=(Button) findViewById(R.id.button);
        input=(EditText) findViewById(R.id.text);
        go.setOnClickListener(this);
        webView.setWebViewClient(new WebViewClient());
        webView.getSettings().setJavaScriptEnabled(true);
        webView.getSettings().setBuiltInZoomControls(true);
        webView.setVerticalScrollBarEnabled(false);
        webView.setHorizontalScrollBarEnabled(false);
        webView.getSettings().setUserAgentString("Mozilla/5.0 (iPhone; U; CPU like Mac OS X; en) AppleWebKit/420+ (KHTML, like Gecko) Version/3.0 Mobile/1A543a Safari/419.3");
        //webView.getSettings().setUserAgentString("Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.4) Gecko/20100101 Firefox/4.0");
        webView.loadUrl("https://www.google.com");

    }

    public void onClick(View v){
        if(v.getId()==go.getId())
        {
            texts = input.getText().toString();
            webView.loadUrl(texts);
        }
    }
}
