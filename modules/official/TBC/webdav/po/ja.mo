Þ    (      \  5         p     q  !         %  #   F  E   j     °  Õ   Î  "   ¤     Ç  .   Ù          "     <    P    i  z   r     í     	     	     +	  "  <	     _
  +   v
  4   ¢
     ×
  ª   é
  °     â   E  -   (     V     r  ¡        "     <     L    h    |              ±  ß   H  0   (  4   Y  6     g   Å  1   -    _  -   n       8   ¬  )   å  )     $   9    ^  k  î  ³   Z  0        ?     U     q  w    $      5   %  ^   [  $   º    ß    ë  !  ø  /   !  .   J!     y!    !     "     ²"  -   Â"    ð"  U   $  ¿   V%  É   &           	                                       
   '   %              "         (                         &       #                                  $                    !           %sClick here%s to mount Gallery on your desktop with a WebDAV client.  Documentation on mounting Gallery with WebDAV is in the %sGallery Codex%s. 'Connect to WebDAV' rule disabled 'OPTIONS Requests' rule disabled Alternative URL missing DAV headers Alternatively, you can enter the following URL in your WebDAV client: Bad URL rewrite configuration Because OPTIONS responses are missing DAV headers, we try to fall back on an alternative URL, but alternative URL responses are also missing DAV headers.  Troubleshooting documentation is in the %sGallery Codex%s. Configuration checked successfully Connect to WebDAV Give davmount resources the correct extension. HTTP auth module disabled HTTP auth plugin disabled Missing DAV headers Most WebDAV clients will fail to connect because the URL rewrite module is disabled.  You should activate the URL rewrite module in the %sSite Admin Plugins option%s and choose either Apache mod_rewrite or ISAPI_Rewrite.  Troubleshooting documentation is in the %sGallery Codex%s. Most WebDAV clients will fail to connect because the URL rewrite rule to generate short WebDAV URLs is disabled.  You should activate the 'Connect to WebDAV' rule in the %sSite Admin URL Rewrite option%s.  Troubleshooting documentation is in the %sGallery Codex%s. Most WebDAV clients will successfully connect.  Documentation on mounting Gallery with WebDAV is in the %sGallery Codex%s. Mount Gallery on your desktop. Mount WebDAV Mount with WebDAV OPTIONS Requests PHP PathInfo rewrite doesn't support the rule to fall back on an alternative URL.  You should uninstall and reinstall the URL rewrite module in the %sSite Admin Plugins option%s and choose either Apache mod_rewrite or ISAPI_Rewrite.  Troubleshooting information is in the %sGallery Codex%s. PHP has no XML support Path to an item (eg. /album/image.jpg.html) Redirect OPTIONS requests so we can set DAV headers. Remote Interfaces Some WebDAV clients, e.g. Mac OS X WebDAVFS, will fail to connect and automated checks failed to find a cause.  Troubleshooting documentation is in the %sGallery Codex%s. Some WebDAV clients, e.g. Mac OS X WebDAVFS, will fail to connect because OPTIONS responses are missing DAV headers.  Troubleshooting documentation is in the %sGallery Codex%s. The URL rewrite rule to fall back on an alternative URL is disabled.  You should activate the WebDAV 'OPTIONS Requests' rule in the %sSite Admin URL Rewrite option%s.  Troubleshooting documentation is in the %sGallery Codex%s. The URL to connect to Gallery with WebDAV is: URL rewrite module disabled Unknown Cause Use short URL because most WebDAV clients don't support query strings.  The Windows WebDAV client requires that you don't add a slash before the %path% variable. WebDAV Mount Instructions WebDAV Settings WebDAV requests not handled You can connect with WebDAV anonymously, but you can't do anything which requires you to login because neither HTTP authentication nor server authentication are enabled in the HTTP auth module.  You should activate HTTP authentication in the settings of the HTTP auth module. You can connect with WebDAV anonymously, but you can't do anything which requires you to login because the HTTP auth module is disabled.  You should activate the HTTP auth module in the %sSite Admin Plugins option%s.  Troubleshooting documentation is in the %sGallery Codex%s. You can't connect with WebDAV because PHP has no XML support on this server.  Troubleshooting documentation is in the %sGallery Codex%s. You can't connect with WebDAV because this server doesn't pass WebDAV requests to Gallery.  Troubleshooting documentation is in the %sGallery Codex%s. Project-Id-Version: Gallery: WebDAV 1.0.9
Report-Msgid-Bugs-To: gallery-translations@lists.sourceforge.net
POT-Creation-Date: 2007-06-14 17:50-0700
PO-Revision-Date: 2007-03-07 11:22+0900
Last-Translator: Kennichi Uehara <ken.w3m+nospam@gmai.com>
Language-Team: Japanese <gallery-translations@lists.sourceforge.net>
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
 %sãããã¯ãªãã¯%sãã¦WebDAVã¯ã©ã¤ã¢ã³ãã§ãã¹ã¯ãããã«Galleryããã¦ã³ããã¦ãã ãããWebDAVã§Galleryããã¦ã³ãããããã®ãã­ã¥ã¡ã³ãã¯%sGalleryCodex%sã«ããã¾ãã ãWebDAVã¸ã®æ¥ç¶ãã«ã¼ã«ã¯ç¡å¹ã§ã ãOPTIONSãªã¯ã¨ã¹ããã«ã¼ã«ã¯ç¡å¹ã§ã ä»£ããã®URLã«DAVããããè¦ã¤ããã¾ãã ä»£ããã«ãããªãã¯WebDAVã¯ã©ã¤ã¢ã³ãã«ä»¥ä¸ã®URLãå¥åãããã¨ãã§ãã¾ã: URL æ¸ãæãã®è¨­å®ãééã£ã¦ãã¾ã OPTIONSã¬ã¹ãã³ã¹ã¯DAVããããè¦ã¤ããããªããããä»£æ¿ã®URLã«é ¼ããã¨ãã¾ãããä»£æ¿ã®URLã®å¿ç­ãDAVããããè¦ã¤ãããã¾ããããã©ãã«ã·ã¥ã¼ãã£ã³ã°ã®ãã­ã¥ã¡ã³ãã¯%sGallery Codex%sã«ããã¾ãã è¨­å®ã®ãã§ãã¯ã«æåãã¾ããã WebDAVã«æ¥ç¶ æ­£ããæ¡å¼µãdavmountãªã½ã¼ã¹ã«ä¸ãã¾ãã HTTP èªè¨¼ã¢ã¸ã¥ã¼ã«ãç¡å¹ã§ã HTTP èªè¨¼ãã©ã°ã¤ã³ãç¡å¹ã§ã DAVããããè¦ã¤ããã¾ãã å¤ãã®WebDAVã¯ã©ã¤ã¢ã³ãã¯URLæ¸ãæãã¢ã¸ã¥ã¼ã«ãç¡å¹ãªãããæ¥ç¶ã«å¤±æããã§ãããã%sãµã¤ãç®¡çãã©ã°ã¤ã³ãªãã·ã§ã³%sã§URLæ¸ãæãã¢ã¸ã¥ã¼ã«ãæå¹åãã¦ãApacheã®mod_rewriteãISAPI_Rewriteã®ã©ã¡ãããé¸æãã¦ãã ããããã©ãã«ã·ã¥ã¼ãã£ã³ã°ã®ãã­ã¥ã¡ã³ãã¯%sGallery Codex%sã«ããã¾ãã ã»ã¨ãã©ã®WebDAVã¯ã©ã¤ã¢ã³ãã¯ç­ãURLãçæãããURLç½®ãæãã¢ã¸ã¥ã¼ã«ãç¡å¹ãªãããæ¥ç¶ã«å¤±æããã§ãããã%sãµã¤ãç®¡çURLç½®ãæããªãã·ã§ã³%sã§ãWebDAVã¸ã®æ¥ç¶ãã«ã¼ã«ãæå¹åãã¹ãã§ãããã©ãã«ã·ã¥ã¼ãã£ã³ã°ã®ãã­ã¥ã¡ã³ãã¯%sGallery Codex%sã«ããã¾ãã ã»ã¨ãã©ã®WebDAVã¯ã©ã¤ã¢ã³ãã¯æ¥ç¶ã«æåããã§ããããWebDAVã§Galleryããã¦ã³ãããããã®ãã­ã¥ã¡ã³ãã¯%sGalleryCodex%sã«ããã¾ãã Galleryãããªãã®PCã«ãã¦ã³ããã¾ã WebDAVããã¦ã³ã WebDAVã§ãã¦ã³ããã OPTIONSãªã¯ã¨ã¹ã PHP PathInfoã®æ¸ãæãã¯ä»£æ¿ã®URLãé ¼ãã«ã¼ã«ããµãã¼ããã¾ããã%sãµã¤ãç®¡çãã©ã°ã¤ã³ãªãã·ã§ã³%sã§URLæ¸ãæãã¢ã¸ã¥ã¼ã«ãåã¤ã³ã¹ãã¼ã«ãã¦Apacheã®mod_rewriteãISAPI_Rewriteã®ã©ã¡ãããé¸æãã¦ãã ããããã©ãã«ã·ã¥ã¼ãã£ã³ã°ã®ãã­ã¥ã¡ã³ãã¯%sGallery Codex%sã«ããã¾ãã PHPãXMLã«å¯¾å¿ãã¦ãã¾ãã ã¢ã¤ãã ã¸ã®ãã¹ (ä¾: /album/image.jpg.html) DAVããããè¨­å®ã§ããããã«OPTIONSãªã¯ã¨ã¹ãããªãã¤ã¬ã¯ããã¾ãã ãªã¢ã¼ãã¤ã³ã¿ã¼ãã§ã¼ã¹ ããã¤ãã®WebDAVã¯ã©ã¤ã¢ã³ã(ä¾: MacOS Xã®WebDAVFS)ã¯æ¥ç¶ã«å¤±æãã¦ãèªåãã§ãã¯ã«ããåå ãè¦ã¤ãããã¨ãã§ããªãã§ãããããã©ãã«ã·ã¥ã¼ãã£ã³ã°ã®ãã­ã¥ã¡ã³ãã¯%sGallery Codex%sã«ããã¾ãã ããã¤ãã®WebDAVã¯ã©ã¤ã¢ã³ã(ä¾ï¼MacOSXã®WebDAVFSç­)ã¯OPTIONSãªã¯ã¨ã¹ãã«DAVããããè¦ã¤ããããªããããæ¥ç¶ã«å¤±æããã§ãããããã©ãã«ã·ã¥ã¼ãã£ã³ã°ã®ãã­ã¥ã¡ã³ãã¯%sGallery Codex%sã«ããã¾ãã ä»£æ¿ã®URLãé ¼ãURLæ¸ãæãã«ã¼ã«ã¯åããã§ãã%sãµã¤ãç®¡çURLæ¸ãæããªãã·ã§ã³%sã§WebDAVã®ãOPTIONSãªã¯ã¨ã¹ããã«ã¼ã«ãæå¹åãã¦ãã ããããã©ãã«ã·ã¥ã¼ãã£ã³ã°ã®ãã­ã¥ã¡ã³ãã¯%sGallery Codex%sã«ããã¾ãã WebDAVã§Galleryã¸æ¥ç¶ããããã®URLã¯: URL æ¸ãæãã¢ã¸ã¥ã¼ã«ãç¡å¹ã§ã åå ä¸æ ã»ã¨ãã©ã®WebDAVã¯ã©ã¤ã¢ã³ããã¯ã¨ãªæå­åããµãã¼ãããªãã®ã§ç­ãURLãä½¿ç¨ãã¦ãã ãããWindowsã®WebDAVã¯ã©ã¤ã¢ã³ãã¯ããªãã%path%å¤æ°ã®åã«ã¹ã©ãã·ã¥ãå ããªãããã«ããå¿è¦ãããã¾ãã WebDAVã®ãã¦ã³ãã®èª¬æ WebDAVã®è¨­å® WebDAVã®ãªã¯ã¨ã¹ãã¯æ±ãã¾ããã å¿åã§ã®WebDAVã®æ¥ç¶ã¯ã§ãã¾ãããHTTPèªè¨¼ããµã¼ãèªè¨¼ãHTTPèªè¨¼ã¢ã¸ã¥ã¼ã«ã§æå¹åããã¦ããªãã®ã§ãã­ã°ã¤ã³ã«å¿è¦ãªåä½ãã§ãã¾ãããHTTPèªè¨¼ã¢ã¸ã¥ã¼ã«ã®è¨­å®ã§HTTPèªè¨¼ãæå¹åãã¹ãã§ãã å¿åã§ã®WebDAVã®æ¥ç¶ã¯ã§ãã¾ãããHTTPèªè¨¼ã¢ã¸ã¥ã¼ã«ãç¡å¹ãªããã­ã°ã¤ã³ã«å¿è¦ãªåä½ãã§ãã¾ããã%sãµã¤ãç®¡çãã©ã°ã¤ã³ãªãã·ã§ã³%sã§HTTPèªè¨¼ã¢ã¸ã¥ã¼ã«ãæå¹åãã¹ãã§ãããã©ãã«ã·ã¥ã¼ãã£ã³ã°ã®ãã­ã¥ã¡ã³ãã¯%sGallery Codex%sã«ããã¾ãã PHPã¯ãã®ãµã¼ãã§XMLããµãã¼ããã¦ããªããããWebDAVã§æ¥ç¶ã§ãã¾ããããã©ãã«ã·ã¥ã¼ãã£ã³ã°ã®ãã­ã¥ã¡ã³ãã¯%sGallery Codex%sã«ããã¾ãã ãã®ãµã¼ãã¯Galleryã¸ã®WebDAVãªã¯ã¨ã¹ããéããªããããWebDAVã§æ¥ç¶ã§ãã¾ããããã©ãã«ã·ã¥ã¼ãã£ã³ã°ã®ãã­ã¥ã¡ã³ãã¯%sGallery Codex%sã«ããã¾ãã 