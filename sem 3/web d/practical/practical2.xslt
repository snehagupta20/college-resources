<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:template match="/transactions">
        <html>
            <body>
                <h2>Bank Transactions</h2>
                <table border="1">
                    <tr>
                        <th>transaction id</th>
                        <th>reciever</th>
                        <th>account number</th>
                        <th>amount transfered</th>
                        <th>date</th>
                        <th>end balance</th>
                    </tr>
                    <xsl:for-each select="line">
                    <tr>
                        <td><xsl:value-of select="transaction_id"/></td>
                        <td><xsl:value-of select="sent_to"/></td>
                        <td><xsl:value-of select="acc_number"/></td>
                        <td><xsl:value-of select="amount_trans"/></td>
                        <td><xsl:value-of select="date"/></td>
                        <td><xsl:value-of select="end_balance"/></td>
                    </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>