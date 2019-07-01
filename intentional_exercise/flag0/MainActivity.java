package com.hacker101.level13;

import android.net.Uri;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MainActivity extends AppCompatActivity {
  protected void onCreate(Bundle paramBundle) {
    super.onCreate(paramBundle);
    setContentView(2131296284);
    WebView webView = (WebView)findViewById(2131165328);
    webView.setWebViewClient(new WebViewClient());
    Uri uri = getIntent().getData();
    str1 = "http://127.0.0.1/xxxxxxxxxx/appRoot";
    String str3 = "";
    if (uri != null) {
      str3 = uri.toString().substring(28);
      StringBuilder stringBuilder = new StringBuilder();
      stringBuilder.append("http://127.0.0.1/xxxxxxxxxx/appRoot");
      stringBuilder.append(str3);
      str1 = stringBuilder.toString();
    } 
    String str2 = str1;
    if (!str1.contains("?")) {
      StringBuilder stringBuilder = new StringBuilder();
      stringBuilder.append(str1);
      stringBuilder.append("?");
      str2 = stringBuilder.toString();
    } 
    try {
      MessageDigest messageDigest = MessageDigest.getInstance("SHA-256");
      messageDigest.update("s00p3rs3cr3tk3y".getBytes(StandardCharsets.UTF_8));
      messageDigest.update(str3.getBytes(StandardCharsets.UTF_8));
      byte[] arrayOfByte = messageDigest.digest();
      BigInteger bigInteger = new BigInteger();
      this(1, arrayOfByte);
      String str = String.format("%064x", new Object[] { bigInteger });
      StringBuilder stringBuilder = new StringBuilder();
      this();
      stringBuilder.append(str2);
      stringBuilder.append("&hash=");
      stringBuilder.append(str);
      webView.loadUrl(stringBuilder.toString());
    } catch (NoSuchAlgorithmException str1) {
      str1.printStackTrace();
    } 
  }
}
