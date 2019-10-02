Imports System.Runtime.InteropServices

Public Class Form1
    <DllImport("winmm.dll")> _
    Private Shared Function mciSendString(ByVal command As String, ByVal buffer As String, ByVal bufferSize As Integer, ByVal hwndCallback As IntPtr) As Integer
    End Function

    Private Sub Button_Open_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button_Open.Click
        mciSendString("set CDAudio door open", vbNullString, 0, IntPtr.Zero)
        Me.Text = "opened"
    End Sub

    Private Sub Button_Close_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button_Close.Click
        mciSendString("set CDAudio door closed", vbNullString, 0, IntPtr.Zero)
        Me.Text = "closed"
    End Sub
End Class
