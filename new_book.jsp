<%-- 
    Document   : admin
    Created on : 16-Mar-2017, 02:41:34
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
            <h2 class="major">New Book</h2>
                                                                <form action="new_book">
							  <div>
								  <br><label for="textfield2">RFID</label>
								  <input type="text" name="rfid" id="textfield2">
								  <label for="textfield3">Book Name</label>
								  <input type="text" name="bname" id="textfield3">
								  <label for="textfield3">Author </label>
								  <input type="text" name="author" id="textfield3">
                                  				  <label for="email">Publication</label>
                                  				  <input type="text" name="publication" id="email"><br>
								  <label for="phone">price</label>
                                                                  <input type="text" name="price" >
								  <label for="address">Date Of Purchase</label>
                                                                  <input type="text" name="dop" id="password"><br>
								  <input type="Submit" value="Enter">
                                                        &nbsp;</div><br><br>
                                                                    <a href="admin.jsp">Go back to Admin</a>
                                                                    </form>
            
        </header>
        </div>
        
    </body>
</html>
