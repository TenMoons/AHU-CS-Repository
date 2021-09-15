<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'index.jsp' starting page</title>
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->
  </head>
  
  <body>BS登录模块<br>
		<form method="post" name="form" action="servlet/CheckServlet">
			<p>
				用户名：
				<input type="text" maxlength="40" size="20" name="name">
			</p>
			<p> 
				&nbsp;密码： 
				<input type="password" maxlength="40" size="20" name="password">
			</p>
			<p>
				<input type="submit" value="登录" name="submit">
				<input type="reset" value="重置" name="clear">
			</p>
			<p>
				&nbsp;
			</p>
			<p>
				&nbsp;
			</p>
			<p>
				&nbsp;
			</p>
		</form>
		<br>
  </body>
</html>
