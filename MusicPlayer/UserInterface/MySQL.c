void GetPathFromTitle(char path[PATH_MAX], char* title)
{
    char QueryString[PATH_MAX] = {"SELECT Path FROM Albums WHERE Title = \""};

    strcat(QueryString, title);
    strcat(QueryString, "\"");

    MYSQL* pConnection = mysql_init(NULL);

    if (!mysql_real_connect(pConnection, "localhost" , "root" , "root", "Albums", 0 , NULL, 0))
    {
        printf("%s\n", mysql_error(pConnection));
        mysql_close(pConnection);
    }

    if (mysql_query(pConnection, QueryString))
    {
        printf("%s\n", mysql_error(pConnection));
        mysql_close(pConnection);
    }

    MYSQL_RES* result = mysql_store_result(pConnection);
  
    if (!result) 
    {
        printf("%s\n", mysql_error(pConnection));
        mysql_close(pConnection);
    }

    MYSQL_ROW row;
    
    while ((row = mysql_fetch_row(result))) 
    { 
        strcpy(path, *row);
        strcat(path, "/");
    }

    mysql_free_result(result);
    mysql_close(pConnection);
}
