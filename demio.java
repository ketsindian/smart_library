/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Model;

import java.io.FileReader;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

/**
 *
 * @author iRobin
 */
public class demio {
    public static void main(String[] args) throws Exception{
        try{
        Class.forName("com.mysql.jdbc.Driver");
            Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/robin","root","root");
            Statement s1=con.createStatement();
            s1.execute("insert into books values('20 12 34 56 67 34 25 75 84 41','s','s','s','s','s')");
            s1.execute("insert into books values('20 12 34 56 67 34 25 75 84 42','s1','s1','s1','s','s')");
            s1.execute("insert into books values('20 12 34 56 67 34 25 75 84 43','s2','s2','s2','s','s')");
            s1.execute("insert into books values('20 12 34 56 67 34 25 75 84 44','s3','s3','s3','s','s')");
            s1.execute("insert into books values('20 12 34 56 67 34 25 75 84 45','s4','s4','s4','s','s')");
            s1.execute("insert into books values('20 12 34 56 67 34 25 75 84 46','s5','s5','s5','s','s')");
        }
        catch(Exception e){
            System.out.println("Exception : "+e);
          }   
    }
}
