<%-- 
    Document   : admin
    Created on : 16-Mar-2017, 03:13:23
    Author     : iRobin
--%>

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
         <div id="wrapper">
            <header id="header">
            <h2 class="major">Welcome Admin</h2>
            
            <form action="new_book.jsp">
                 <input type="Submit" value="New Record">
            </form><br>
            <form action="issue_book.jsp">
                 <input type="Submit" value="Issue New Book">
            </form><br>
            <form action="return_book.jsp">
                 <input type="Submit" value="Issued Book">
            </form>
            <a href="logout">Logout</a>
        </header>
        </div>
    </body>
</html>
