<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="webform._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <div class="jumbotron">
        <ItemTemplate>
                Name:
                <asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("Name") %>'></asp:TextBox>
                <br />
                <br />
                Password
                <asp:TextBox ID="TextBox2" runat="server" Text='<%# Bind("Password") %>'></asp:TextBox>
                <br />
                <br />
                Text:
                <asp:TextBox ID="TextBox3" runat="server" Text="Hello World !"></asp:TextBox>
                <br />
                <br />
                Comment:
                <asp:TextBox ID="TextBox4" runat="server" TextMode="MultiLine" Rows="5" Text="Hello World !"></asp:TextBox>
                <br />
                <br />
                Is Student:
                <asp:CheckBox ID="CheckBox1" runat="server" Checked='<%# Bind("IsStudent") %>' />
                <br />
                <br />
                Gender:
                Male: <asp:RadioButton ID="RadioButton1" runat="server" />
                Female: <asp:RadioButton ID="RadioButton2" runat="server" />
                <br />
                <br />
                Department:
                <asp:DropDownList ID="DropDownList1" runat="server">
                    <asp:ListItem>Select</asp:ListItem>
                    <asp:ListItem>Computer Science</asp:ListItem>
                    <asp:ListItem>Information Technology</asp:ListItem>
                    <asp:ListItem>Electronics</asp:ListItem>
                    <asp:ListItem>Electrical</asp:ListItem>
                </asp:DropDownList>
                <br />  
                <br />
                <asp:Button ID="Button1" runat="server" Text="Save Form" />
            </ItemTemplate>
        

</div>


</asp:Content>

