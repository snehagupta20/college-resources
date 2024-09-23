<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/bank_account_details">
<html>
    <head>
    </head>
    <body>
        <h2>bank account details</h2>
        <table border="1">
            <tr>
                <th>acc number</th>
                <th>acc type</th>
                <th>balance</th>
                <th>customer id</th>
                <th>customer name</th>
            </tr>
            <xsl:for-each select="account">
            <tr>
                <td><xsl:value-of select="ac_no"/></td>
                <td><xsl:value-of select="Ac_type"/></td>
                <td><xsl:value-of select="balance"/></td>
                <td><xsl:value-of select="customer_id"/></td>
                <td><xsl:value-of select="customer_name"/></td>
            </tr>
            </xsl:for-each>
        </table>
    </body>
</html>
</xsl:template>
</xsl:stylesheet>