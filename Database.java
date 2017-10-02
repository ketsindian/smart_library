/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Model;

import java.sql.Connection;
import java.sql.DriverManager;

/**
 *
 * @author iRobin
 */

public class Database {
   public static Connection con;
    public static Connection database(){
    try
    {
        Class.forName("com.mysql.jdbc.Driver");
        con=DriverManager.getConnection("jdbc:mysql://localhost:3306/robin","root","root");
        System.out.println("Connection established");
    }
    catch(Exception e)
    {
        System.out.println(e);
    }
    return con;
    }
    
}

