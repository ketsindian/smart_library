<%-- 
    Document   : tables
    Created on : 16-Mar-2017, 02:10:05
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
                          <a href="admin.jsp">Go back to Admin</a>
            
            <br><br><br>
		<table class="table table-striped table-bordered table-hover">
			<tr>
				<th>RFID</th>
				<th>BOOK NAME</th>
				<th>STUDENT NAME</th>
                                <th>DATE OF ISSUING</th>
                                <th>DATE OF RETURN</th>
                                <th>STATUS</th>
                                <th>UPDATE</th>
			</tr>
                        <%
                           try
                           {
                               Connection con = Database.database();
                               String str = "select * from book_issue where status='Issued' ";
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
                                <td><%= rs.getString(6) %></td>
                                <td><a href="update.jsp?<%=rs.getString(1)%>">Update</a></td>
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
