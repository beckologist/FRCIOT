
/**
 * Write a description of class ThingworxSend here.
 * 
 * @author (David Kaiser) 
 * @version (V1.0.0)
 */

import java.io.*;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;


public class ThingworxSend
{

    public static void main(String[] args)
    {

        //HTTP POST test
//        try{
//            String input1 = "xxx";
//            //URL url = new URL("http://10.5.37.38:8080/Thingworx/Things/IOTTestBoard/Properties/*");
//            URL url = new URL("http://10.5.37.201:5801/api/537");
//            HttpURLConnection conn = (HttpURLConnection) url.openConnection();
//            conn.setDoOutput(true);
//            conn.setRequestMethod("PUT");
//            conn.setRequestProperty("Content-Type", "application/json");
//            conn.setRequestProperty("appKey", "xxxxxxxxxxxxxxx"); 
//            OutputStreamWriter os = new OutputStreamWriter(conn.getOutputStream());
//            os.write(input1);
//            os.close();
//            conn.getInputStream();
//           System.out.println(conn.getResponseCode());
//       
//          catch(Exception e){
//              
//       }
        
        
       InputStreamReader isReader = new InputStreamReader(System.in);
       BufferedReader bufReader = new BufferedReader(isReader);
       
       String inputStr = "";
   
           try{
               while(inputStr != null){
                   String output = "xxx";
                   inputStr=bufReader.readLine();
                   if(inputStr != null && (inputStr.length() > 9)){
                       //int myParseIndex = inputStr.indexOf("payload::");
                       String myMessageType = inputStr.substring(0,9);
                       //System.out.println("Message type: " + myMessageType);
                       if(myMessageType.equals("payload::")){
                           //System.out.println("Here");
                           int myEndParseIndex = inputStr.indexOf("payload End::");
                           //System.out.println("End parse index: " + myEndParseIndex);
                           output = (inputStr.substring(9,myEndParseIndex));
                           
                           //Http Send
                           String myURLString = "http://" + args[0] + ":" + args[1] + "/api/537/Things/Data";
                           //System.out.println(myURLString);
                           //URL url = new URL("http://10.5.37.201:5801/api/537/Things/Data");
                           URL url = new URL(myURLString);
                           HttpURLConnection conn = (HttpURLConnection) url.openConnection();
                           conn.setDoOutput(true);
                           conn.setRequestMethod("PUT");
                           conn.setRequestProperty("Content-Type", "application/json");
                           //conn.setRequestProperty("appKey", "b25c870b-1d4e-4f19-978e-2521bdb1929f"); 
                           OutputStreamWriter os = new OutputStreamWriter(conn.getOutputStream());
                           os.write(output);
                           os.close();
                           conn.getInputStream();
                           System.out.println(conn.getResponseCode());
                           
                       }
                       else{
                           System.out.println(inputStr);
                       }
                           
                    } else{
                        System.out.println("input string is null");
                    } 
            }
           }
           catch(Exception e){
               System.out.println(e);
              e.printStackTrace();
           }    
           
       }
       
    }

