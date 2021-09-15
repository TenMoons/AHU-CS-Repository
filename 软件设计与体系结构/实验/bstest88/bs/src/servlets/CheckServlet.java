package servlets;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import dbManager.*;

public class CheckServlet extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public CheckServlet() {
		super();
	}

	/**
	 * The doPost method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to post.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String name = "";
		String password = "";
		boolean ok = false;
		if(request!=null){
			name=request.getParameter("name");
			password=request.getParameter("password");
	//		DBConnectionManager dbcon = new DBConnectionManager();
	//		Connection con = dbcon.getConnection();
	//		Statement stmt;
	//		ResultSet rs;
	//		try {
	//			stmt = con.createStatement();
	//			rs = stmt.executeQuery("select * from users where username=\'"+name+"\' and password=\'"+password+"\'");
	//			if(rs.next()){
	//				ok = true;
	//			}
	//			else ok = false;
	//			rs.close();
	//			stmt.close();
	//		} catch (SQLException e) {
	//			// TODO Auto-generated catch block
	//			ok = false;
	//		}
			ok = true;
		}
		response.setContentType("text/html;charset=gb2312");
		PrintWriter out = response.getWriter();
		out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
		out.println("<HTML>");
		out.println("  <HEAD><TITLE>A Servlet</TITLE></HEAD>");
		out.println("  <BODY>");
		if(ok==true){
			out.println("µÇÂ¼³É¹¦£¡"+name);
		}
		else out.println("µÇÂ¼Ê§°Ü£¡");
		out.println("  </BODY>");
		out.println("</HTML>");
		out.flush();
		out.close();
	}

}
