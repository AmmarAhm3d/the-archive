<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="WebApplication1._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <div class="jumbotron">
        <img src="https://www.pngkey.com/png/detail/1-13336_instagram-png-file-instagram-old-logo-png.png" alt="InstaLogo.png" style="height:200px;width:200px;"/>
        <h1><b>To Illustrate form based tags</b></h1><br /><br />
      <label for="txtName">This is a text box to enter any text</label>
       <asp:TextBox ID="txtName" runat="server"></asp:TextBox><br /><br />
       <label for="txtPassword">This is a text box to enter password</label>
        <asp:TextBox ID="txtPassword" TextMode="password"
runat="server"></asp:TextBox>
        <br /><br />
       <label for="cmntbox">This is a text area to enter large text</label>
        <asp:TextBox TextMode="MultiLine" Rows="3" runat="server"></asp:TextBox><br />
        <label>This is a button.</label>
        <asp:Button ID="click" runat="server" Text="Click" /><br /><br />
        <label><u><b>Radio options</b></u></label><br />
        <asp:RadioButton ID="yes" Text="YES" runat="server" />
        <asp:RadioButton ID="no" Text="NO" runat="server" /><br /><br />
        <label><u><b>Checkbox Options</b></u></label><br />
        <asp:CheckBox Text="Sunday" runat="server" />
        <asp:CheckBox Text="Monday" runat="server" />
        <asp:CheckBox Text="Tuesday" runat="server" /><br /><br />
        <label><u><b>Menu driven options</b></u></label>
        <asp:DropDownList runat="server">
            <asp:ListItem Value="volvo"></asp:ListItem>
            <asp:ListItem Value="saab"></asp:ListItem>
            <asp:ListItem Value="fiat"></asp:ListItem>
            <asp:ListItem Value="audi"></asp:ListItem>

        </asp:DropDownList>
</div>


</asp:Content>

