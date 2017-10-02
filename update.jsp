<%-- 
    Document   : update
    Created on : 16-Mar-2017, 02:33:07
    Author     : iRobin
--%>

<%@page import="Model.Database"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
         <%
            try{
            Connection con=Database.database();
            Statement s=con.createStatement();
            System.out.println(1);
            System.out.println(request.getQueryString());
            s.executeUpdate("update book_issue set status='Returned', date_of_return='"+new java.util.Date()+"'  where RFID='"+request.getQueryString()+"'");
            System.out.println(2);
            }catch(Exception e){
                System.out.println(e);
            }
            response.sendRedirect("return_book.jsp");
        %>
    </body>
</html>
