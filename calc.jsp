<%@ page contentType="text/html; charset=UTF-8" %>
<html>
<head><title>calculator</title>
  <style type="text/css">
 .a{ width:5em; height:3em; }
  </style>

</head>
<body>
<h2>Calculator</h2><br>
<form method=post action="calculator">
 <input type=text name=number1 class="a">
 <select name=operator class="a">
  <option selected>+</option>
  <option>-</option>
  <option>*</option>
  <option>/</option>
 </select>
 <input type=text name=number2 class="a">
 <input type=submit value="=" class="a">
</form> </body> </html>