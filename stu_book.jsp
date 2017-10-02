<%-- 
    Document   : stu_book
    Created on : 16-Mar-2017, 04:06:52
    Author     : iRobin
--%>

<%@page import="Model.Database"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
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
         <div class="table-responsive"><br><br>
                          <a href="logout">Logout</a>
            
            <br><br><br>
            <h1 align="center">Books Available</h1>
		<table class="table table-striped table-bordered table-hover">
			<tr>
				<th>RFID</th>
				<th>BOOK NAME</th>
				<th>AUTHOR</th>
                                <th>PUBLICATION</th>
                                <th>PRICE</th>
			</tr>
                        <%
                           try
                           {
                               Connection con = Database.database();
                               String str = "select * from books ";
                               Statement stmp = con.createStatement();
                               ResultSet rs = stmp.executeQuery(str);
                               while(rs.next())
                               {
                            %>
			<tr>
				<td><%= rs.getString(1)%></td>
                                <td><%= rs.getString(2) %></td>
				<td><%= rs.getString(3) %></td>
                                <td><%= rs.getString(4) %></td>
                                <td><%= rs.getString(5) %></td>
			</tr>
                          <% }%>
		</table>
        </div>
                
        <%
            }catch(Exception e)
            {
            
            }
            %>
    </body>
</html>
