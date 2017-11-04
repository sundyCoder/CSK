#Sundy
##VpnService

The interface is running on Internet Protocol (IP), so packets are always started with IP headers. The application then completes a VPN connection by processing and exchanging packets with the remote server over a tunnel.

###prepare(Context)
	The former deals with user action and stops the VPN connection created by another application

###establish()
	creates a VPN interface using the parameters supplied to the VpnService.Builder.
An application must call prepare(Context) to grant the right to use other methods in this class, and the right can be revoked at any time.

###Here are the general steps to create a VPN connection:
1. When the user presses the button to connect, call prepare(Context) and launch the returned intent, if non-null.
1. When the application becomes prepared, start the service.
1. Create a tunnel to the remote server and negotiate the network parameters for the VPN connection.
1. Supply those parameters to a VpnService.Builder and create a VPN interface by calling establish().
1. Process and exchange packets between the tunnel and the returned file descriptor.
1. When onRevoke() is invoked, close the file descriptor and shut down the tunnel gracefully.

Services extended this class need to be declared with appropriate permission and intent filter. Their access must be secured by BIND_VPN_SERVICE permission, and their intent filter must match SERVICE_INTERFACE action. Here is an example of declaring a VPN service in AndroidManifest.xml:

	 <service android:name=".ExampleVpnService"
	         android:permission="android.permission.BIND_VPN_SERVICE">
	     <intent-filter>
	         <action android:name="android.net.VpnService"/>
	     </intent-filter>
	 </service>



MainActivity->startVPN()=>onActivityResult()->ComponentName service = startService(intent)->run()

	   setup_network();
	   setup_workers();
	   wait_to_close();
		  LocalServer();
             run();
              LocalServerHandler();
                 run();
                   LocalServerForwarder.connect(client, target, vpnService);
                      clientServer.start();
            		  serverClient.start();
				  