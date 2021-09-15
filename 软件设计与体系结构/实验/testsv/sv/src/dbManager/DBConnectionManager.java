package dbManager;
import java.sql.Connection;
import java.sql.DriverManager;

public class DBConnectionManager {
	private String driverName = 
"net.sourceforge.jtds.jdbc.Driver"; 
	private String url = 
				"jdbc:jtds:sqlserver://localhost:1433/test";
	private String user = "sa";
	private String password = "sa";

	public void setDriverName(String newDriverName) {
        	this.driverName = newDriverName;
    		}
    	public String getDriverName() {
        	return driverName;
    		}
	
	public void setUrl(String newUrl) {
	        this.url = newUrl;
	    	}
   	
	public String getUrl() {
	        return url;
	    	}
	public void setUser(String newUser) {
	        this.user = newUser;
		}
	public String getUser() {
	        return user;
		}
	public void setPassword(String newPassword) {
	        this.password = newPassword;
	    	}
	public String getPassword() {
	        return password;
	    	}
	
	public Connection getConnection() {
	     try {
	         Class.forName(driverName);
	         return DriverManager.getConnection(url, user, password);
	     }
	        catch (Exception e) {
	            e.printStackTrace();
	            return null;
	        	}
	    	}
	
}
