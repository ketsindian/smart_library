<%-- 
    Document   : issue_book
    Created on : 16-Mar-2017, 03:04:18
    Author     : iRobin
--%>

<%@page import="java.util.Calendar"%>
<%@page import="java.sql.Date"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
<%@page import="java.io.FileReader"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
		<title>AIDC Library</title>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
		<link rel="stylesheet" href="assets/css/main.css" />
		<!--[if lte IE 9]><link rel="stylesheet" href="assets/css/ie9.css" /><![endif]-->
		<noscript><link rel="stylesheet" href="assets/css/noscript.css" /></noscript>
	</head>
    <body>
        <%
            Calendar cal=Calendar.getInstance();
            System.out.println("Date = "+ cal.getTime());
            cal.add(Calendar.DATE, 7);
            System.out.println("Date = "+ cal.getTime());
            String s="",id="",bname="",flag="0",date=""+cal.getTime();
            try{
        FileReader fr=new FileReader("/home/katty/RFID.txt");    
          int i;    
          while((i=fr.read())!=-1){  
              s=s+(char)i;
          System.out.print((char)i);
          
          }    
          fr.close();
          System.out.println(""+s);
          System.out.println("Gulabooooo "+s);
          
          Class.forName("com.mysql.jdbc.Driver");
            Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/robin","root","root");
            Statement s1=con.createStatement();
            ResultSet rs=s1.executeQuery("select * from books");
            while(rs.next()){
                System.out.println(rs.getString(1));
                System.out.println(rs.getString(2));
                System.out.println(rs.getString(3));
                System.out.println(rs.getString(4));
                System.out.println(rs.getString(5));
                System.out.println(rs.getString(6));
                if(s.equals(""+rs.getString(1))){
                   flag="1";
                id=rs.getString(1);
                bname=rs.getString(2);}
            }
          System.out.println(flag);
        }
        catch(Exception e){
            System.out.println("Exception : "+e);
          }
       if(id!="")
       {
       %>
                
         <div id="wrapper">
            <header id="header">
            <h2 class="major">Issue Book</h2>
                                                                <form action="issue_book">
							  <div>
								  <br><label for="textfield2">RFID</label>
                                                                  <input type="text" name="rfid" id="textfield2" value="<%=id%>" disabled="true">
								  <label for="textfield3">Book Name</label>
                                                                  <input type="text" name="bname" id="textfield3" value="<%=bname%>" disabled="true">
								  <label for="textfield3">Student Enrollment No. </label>
								  <input type="text" name="stu" id="textfield3">
                                  				  <label for="email">Date Of Issue</label>
                                                                  <input type="text" name="doi" id="email" value="<%=new java.util.Date()%>" disabled="true"><br>
								  <label for="phone">Date Of Return</label>
                                                                  <input type="text" name="dor"  value="<%=date%>" disabled="true"><br>
								  <input type="Submit" value="Issue Book">
                                                        &nbsp;</div>
                                                                    <br><br>
                                                                    <a href="admin.jsp">Go back to Admin</a>
                                                                        
                                                                    </form>
            
        </header>
        </div>
       <%
            }
            else
            {
                response.sendRedirect("no_record.jsp");
            }
        %>
    </body>
</html>
