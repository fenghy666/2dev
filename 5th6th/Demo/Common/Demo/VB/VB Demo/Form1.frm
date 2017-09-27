VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Led调试"
   ClientHeight    =   8430
   ClientLeft      =   -15
   ClientTop       =   375
   ClientWidth     =   10215
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   8430
   ScaleWidth      =   10215
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command9 
      Caption         =   "Command9"
      Height          =   735
      Left            =   6360
      TabIndex        =   59
      Top             =   5040
      Width           =   855
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   5280
      Top             =   7080
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.TextBox tShowTime 
      Height          =   375
      Left            =   4080
      TabIndex        =   54
      Text            =   "1"
      Top             =   6600
      Width           =   855
   End
   Begin VB.TextBox tRunSpeet 
      Height          =   375
      Left            =   4080
      TabIndex        =   52
      Text            =   "1"
      Top             =   6240
      Width           =   855
   End
   Begin VB.ComboBox CStunt 
      Height          =   300
      ItemData        =   "Form1.frx":0000
      Left            =   3720
      List            =   "Form1.frx":001C
      Style           =   2  'Dropdown List
      TabIndex        =   50
      Top             =   5880
      Width           =   1215
   End
   Begin VB.PictureBox dlg 
      Height          =   480
      Left            =   0
      ScaleHeight     =   420
      ScaleWidth      =   1140
      TabIndex        =   58
      Top             =   7800
      Width           =   1200
   End
   Begin VB.CommandButton Command8 
      Caption         =   "选择"
      Height          =   300
      Left            =   4560
      TabIndex        =   49
      Top             =   7200
      Width           =   615
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1320
      TabIndex        =   48
      Top             =   7200
      Width           =   3015
   End
   Begin VB.ComboBox cFontColor 
      Height          =   300
      ItemData        =   "Form1.frx":0068
      Left            =   3720
      List            =   "Form1.frx":0075
      Style           =   2  'Dropdown List
      TabIndex        =   45
      Top             =   5400
      Width           =   1215
   End
   Begin VB.TextBox tFontSize 
      Height          =   375
      Left            =   4080
      TabIndex        =   44
      Text            =   "12"
      Top             =   4800
      Width           =   855
   End
   Begin VB.TextBox programOrd 
      Height          =   375
      Left            =   4080
      TabIndex        =   41
      Text            =   "0"
      Top             =   4200
      Width           =   855
   End
   Begin VB.Frame Frame1 
      Caption         =   "Frame1"
      Height          =   3735
      Left            =   240
      TabIndex        =   8
      Top             =   120
      Width           =   9615
      Begin VB.TextBox SochetIp 
         Height          =   375
         Left            =   3360
         TabIndex        =   57
         Text            =   "192.168.10.147"
         Top             =   240
         Width           =   2415
      End
      Begin VB.ComboBox sendMode 
         Height          =   300
         ItemData        =   "Form1.frx":0085
         Left            =   1560
         List            =   "Form1.frx":009B
         Style           =   2  'Dropdown List
         TabIndex        =   39
         Top             =   3240
         Width           =   1215
      End
      Begin VB.CommandButton Command2 
         Caption         =   "删除屏幕"
         Height          =   600
         Left            =   6360
         TabIndex        =   37
         Top             =   2160
         Width           =   1800
      End
      Begin VB.CommandButton Command7 
         Caption         =   "设置屏幕参数"
         Height          =   735
         Left            =   6360
         TabIndex        =   35
         Top             =   1200
         Width           =   1815
      End
      Begin VB.CommandButton Command1 
         Caption         =   "添加屏幕"
         Height          =   615
         Left            =   6360
         TabIndex        =   33
         Top             =   360
         Width           =   1815
      End
      Begin VB.ComboBox pBaut 
         Height          =   300
         ItemData        =   "Form1.frx":00EB
         Left            =   4200
         List            =   "Form1.frx":00F5
         Style           =   2  'Dropdown List
         TabIndex        =   32
         Top             =   2760
         Width           =   1215
      End
      Begin VB.ComboBox pCom 
         Height          =   300
         ItemData        =   "Form1.frx":0106
         Left            =   1560
         List            =   "Form1.frx":0108
         Style           =   2  'Dropdown List
         TabIndex        =   30
         Top             =   2760
         Width           =   1215
      End
      Begin VB.TextBox FreqPar 
         Height          =   375
         Left            =   4440
         TabIndex        =   28
         Text            =   "0"
         Top             =   2160
         Width           =   855
      End
      Begin VB.ComboBox RowOrder 
         Height          =   300
         ItemData        =   "Form1.frx":010A
         Left            =   1560
         List            =   "Form1.frx":0117
         Style           =   2  'Dropdown List
         TabIndex        =   26
         Top             =   2280
         Width           =   1215
      End
      Begin VB.ComboBox DataOE 
         Height          =   300
         ItemData        =   "Form1.frx":0131
         Left            =   4080
         List            =   "Form1.frx":013B
         Style           =   2  'Dropdown List
         TabIndex        =   24
         Top             =   1800
         Width           =   1215
      End
      Begin VB.ComboBox DataDa 
         Height          =   300
         ItemData        =   "Form1.frx":014F
         Left            =   1560
         List            =   "Form1.frx":0159
         Style           =   2  'Dropdown List
         TabIndex        =   22
         Top             =   1800
         Width           =   1215
      End
      Begin VB.ComboBox PixelMode 
         Height          =   300
         ItemData        =   "Form1.frx":0175
         Left            =   3960
         List            =   "Form1.frx":0182
         Style           =   2  'Dropdown List
         TabIndex        =   20
         Top             =   1320
         Width           =   1215
      End
      Begin VB.ComboBox ScreenType 
         Height          =   300
         ItemData        =   "Form1.frx":0196
         Left            =   1560
         List            =   "Form1.frx":01A3
         Style           =   2  'Dropdown List
         TabIndex        =   18
         Top             =   1320
         Width           =   1215
      End
      Begin VB.TextBox ScreenHeigh 
         Height          =   375
         Left            =   5040
         TabIndex        =   16
         Text            =   "32"
         Top             =   720
         Width           =   855
      End
      Begin VB.TextBox ScreenWidth 
         Height          =   375
         Left            =   3360
         TabIndex        =   14
         Text            =   "128"
         Top             =   840
         Width           =   855
      End
      Begin VB.TextBox ControlType 
         Height          =   375
         Left            =   1560
         TabIndex        =   12
         Text            =   "852"
         Top             =   840
         Width           =   855
      End
      Begin VB.TextBox ScreenNO 
         Height          =   375
         Left            =   1680
         TabIndex        =   10
         Text            =   "1"
         Top             =   240
         Width           =   855
      End
      Begin VB.Label Label20 
         Caption         =   "IP"
         Height          =   255
         Left            =   2880
         TabIndex        =   56
         Top             =   360
         Width           =   495
      End
      Begin VB.Label Label13 
         Caption         =   "通讯模式"
         Height          =   255
         Index           =   6
         Left            =   480
         TabIndex        =   40
         Top             =   3240
         Width           =   975
      End
      Begin VB.Label Label2 
         Caption         =   "Label2"
         Height          =   255
         Left            =   8400
         TabIndex        =   38
         Top             =   2520
         Width           =   1575
      End
      Begin VB.Label Label7 
         Caption         =   "Label7"
         Height          =   255
         Left            =   8400
         TabIndex        =   36
         Top             =   1680
         Width           =   1695
      End
      Begin VB.Label Label1 
         Caption         =   "Label1"
         Height          =   255
         Left            =   8400
         TabIndex        =   34
         Top             =   600
         Width           =   1695
      End
      Begin VB.Label Label13 
         Caption         =   "波特率"
         Height          =   255
         Index           =   5
         Left            =   3120
         TabIndex        =   31
         Top             =   2760
         Width           =   975
      End
      Begin VB.Label Label13 
         Caption         =   "串口名称"
         Height          =   255
         Index           =   4
         Left            =   480
         TabIndex        =   29
         Top             =   2760
         Width           =   975
      End
      Begin VB.Label Label14 
         Caption         =   "扫描点频（0-6）"
         Height          =   255
         Left            =   3000
         TabIndex        =   27
         Top             =   2280
         Width           =   1455
      End
      Begin VB.Label Label13 
         Caption         =   "行序模式"
         Height          =   255
         Index           =   3
         Left            =   480
         TabIndex        =   25
         Top             =   2280
         Width           =   975
      End
      Begin VB.Label Label13 
         Caption         =   "极性"
         Height          =   255
         Index           =   2
         Left            =   3000
         TabIndex        =   23
         Top             =   1800
         Width           =   975
      End
      Begin VB.Label Label13 
         Caption         =   "数据极性"
         Height          =   255
         Index           =   1
         Left            =   480
         TabIndex        =   21
         Top             =   1800
         Width           =   975
      End
      Begin VB.Label Label13 
         Caption         =   "点阵类型"
         Height          =   255
         Index           =   0
         Left            =   2880
         TabIndex        =   19
         Top             =   1320
         Width           =   975
      End
      Begin VB.Label Label12 
         Caption         =   "显示屏类型"
         Height          =   255
         Left            =   480
         TabIndex        =   17
         Top             =   1320
         Width           =   975
      End
      Begin VB.Label Label11 
         Caption         =   "屏高"
         Height          =   255
         Left            =   4440
         TabIndex        =   15
         Top             =   840
         Width           =   1215
      End
      Begin VB.Label Label10 
         Caption         =   "屏宽"
         Height          =   255
         Left            =   2760
         TabIndex        =   13
         Top             =   840
         Width           =   1215
      End
      Begin VB.Label Label9 
         Caption         =   "控制卡型号"
         Height          =   255
         Left            =   480
         TabIndex        =   11
         Top             =   840
         Width           =   1215
      End
      Begin VB.Label Label8 
         Caption         =   "当前屏幕地址"
         Height          =   255
         Left            =   480
         TabIndex        =   9
         Top             =   360
         Width           =   1575
      End
   End
   Begin VB.CommandButton Command6 
      Caption         =   "发送屏幕信息"
      Height          =   735
      Left            =   5520
      TabIndex        =   4
      Top             =   5880
      Width           =   1815
   End
   Begin VB.CommandButton Command5 
      Caption         =   "添加文件到当前图文区域"
      Height          =   735
      Left            =   5520
      TabIndex        =   3
      Top             =   5040
      Width           =   495
   End
   Begin VB.CommandButton Command4 
      Caption         =   "添加图文区域"
      Height          =   735
      Left            =   5520
      TabIndex        =   2
      Top             =   4080
      Width           =   1815
   End
   Begin VB.CommandButton Command3 
      Caption         =   "添加节目"
      Height          =   615
      Left            =   240
      TabIndex        =   0
      Top             =   4080
      Width           =   1785
   End
   Begin VB.Label Label21 
      Caption         =   "Label21"
      Height          =   255
      Left            =   7560
      TabIndex        =   60
      Top             =   5520
      Width           =   615
   End
   Begin VB.Label Label19 
      Caption         =   "停留时间（0-65525）"
      Height          =   255
      Left            =   2160
      TabIndex        =   55
      Top             =   6600
      Width           =   1815
   End
   Begin VB.Label Label18 
      Caption         =   "运行速度（0-63）"
      Height          =   255
      Left            =   2160
      TabIndex        =   53
      Top             =   6240
      Width           =   1815
   End
   Begin VB.Label Label13 
      Caption         =   "显示特技"
      Height          =   255
      Index           =   8
      Left            =   2640
      TabIndex        =   51
      Top             =   5880
      Width           =   975
   End
   Begin VB.Label Label17 
      Caption         =   "选择文件"
      Height          =   255
      Left            =   360
      TabIndex        =   47
      Top             =   7200
      Width           =   855
   End
   Begin VB.Label Label13 
      Caption         =   "字体颜色"
      Height          =   255
      Index           =   7
      Left            =   2640
      TabIndex        =   46
      Top             =   5400
      Width           =   975
   End
   Begin VB.Label Label16 
      Caption         =   "字体大小"
      Height          =   255
      Left            =   2880
      TabIndex        =   43
      Top             =   4800
      Width           =   1095
   End
   Begin VB.Label Label15 
      Caption         =   "节目号"
      Height          =   255
      Left            =   2880
      TabIndex        =   42
      Top             =   4320
      Width           =   1575
   End
   Begin VB.Label Label6 
      Caption         =   "Label6"
      Height          =   255
      Left            =   7680
      TabIndex        =   7
      Top             =   6120
      Width           =   1575
   End
   Begin VB.Label Label5 
      Caption         =   "Label5"
      Height          =   255
      Left            =   7560
      TabIndex        =   6
      Top             =   5160
      Width           =   1815
   End
   Begin VB.Label Label4 
      Caption         =   "Label4"
      Height          =   255
      Left            =   7680
      TabIndex        =   5
      Top             =   4440
      Width           =   1695
   End
   Begin VB.Label Label3 
      Caption         =   "Label3"
      Height          =   255
      Left            =   360
      TabIndex        =   1
      Top             =   4800
      Width           =   1695
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
  Dim a As Integer
  
  Dim iControlType, iScreenNo, iSendMode, iWidth, iHeight, iScreenType, iPixelMode, iDataDA, iDataOE, iRowOrder, iFreqPar, iSocketPort, iStaticIPMode, iServerMode, iServerPort, iWiFiPort, iGprsPort As Integer
  Dim iBaud As Long
  Dim sCom, sSocketIP, sBarcode, sNetworkID, sServerIP, sServerAccessUser, sServerAccessPassword, sWiFiIP, sGprsIP, sGprsID  As String
  Dim m_bSendBusy As Boolean '此变量在数据更新中非常重要，请务必保留。
  
  


Private Sub Combo4_Change()

End Sub

Private Sub Command1_Click()
'  DllApp = GetWindow(vbNullString, "新建 文本文档.txt - 记事本")
  iControlType = Val(Me.ControlType.Text)
  
  iScreenNo = Val(Me.ScreenNO.Text)
  iSendMode = 2
  iWidth = Val(Me.ScreenWidth.Text)
  iHeight = Val(Me.ScreenHeigh.Text)
  iScreenType = Me.ScreenType.ListIndex
  
  iPixelMode = Me.PixelMode.ListIndex
  iDataDA = Me.DataDa.ListIndex
  iDataOE = Me.DataOE.ListIndex
  iRowOrder = Me.RowOrder.ListIndex
  iFreqPar = Val(Me.FreqPar.Text)
  sCom = Me.pCom.Text
  iBaud = Val(Me.pBaut.Text) ' 57600
  iSocketPort = 5005
  sSocketIP = Me.SochetIp.Text
  iStaticIPMode = 0
  iServerMode = 0
  sBarcode = ""
  sNetworkID = ""
  sServerIP = ""
  iServerPort = 5005
  sServerAccessUser = ""
  sServerAccessPassword = ""
  iWiFiPort = 5005
  sWiFiIP = "192.168.100.1"
  sGprsIP = ""
  iGprsPort = 5005
  sGprsID = ""
  
  a = -1
  a = Initialize(0, AddressOf CallBack)
  a = -1
  a = AddScreen(iControlType, iScreenNo, iSendMode, iWidth, iHeight, iScreenType, iPixelMode, iDataDA, iDataOE, iRowOrder, _
   0, iFreqPar, sCom, iBaud, sSocketIP, iSocketPort, iStaticIPMode, iServerMode, sBarcode, sNetworkID, sServerIP, iServerPort, _
  sServerAccessUser, sServerAccessPassword, sWiFiIP, iWiFiPort, sGprsIP, iGprsPort, sGprsID, "ScreenStatus.ini")
              
  Label1.Caption = CStr(a)
End Sub

Private Sub Command2_Click()
 iScreenNo = iScreenNo
 
  b = -1
  b = DeleteScreen(1)
  Label2.Caption = CStr(b)

End Sub

Private Sub Command3_Click()
   a = -1
   a = AddScreenProgram(iScreenNo, 0, 0, 65535, 11, 26, 2011, 11, 26, 1, 1, 1, 1, 1, 1, 1, 0, 0, 23, 59)
   Label3.Caption = CStr(a)
End Sub

Private Sub Command4_Click()
Dim nProgramOrd As Long

   a = -1
   nProgramOrd = Val(Me.programOrd.Text)
   
   a = AddScreenProgramBmpTextArea(iScreenNo, nProgramOrd, 0, 0, iWidth, iHeight)
Label4.Caption = CStr(a)
End Sub

Private Sub Command5_Click()
Dim Filename As String
Dim nFontSize As Integer
Dim nFontColor As Integer
Dim nStunt As Integer
Dim nRunSpeet As Integer
Dim nShowTime As Integer


nFontSize = Val(Me.tFontSize.Text)
Select Case Me.cFontColor.ListIndex
    Case 0
        nFontColor = 255
    Case 1
        nFontColor = 65280
    Case 2
        nFontColor = 65535
End Select
If Text1.Text = "" Then
    MsgBox "先选择文本文件"
    Exit Sub
End If

Filename = Text1.Text
nStunt = CStunt.ListIndex
nRunSpeet = Val(Me.tRunSpeet.Text)
nShowTime = Val(Me.tShowTime.Text)


    nProgramOrd = Val(Me.programOrd.Text)
   a = -1
   a = AddScreenProgramAreaBmpTextFile(iScreenNo, nProgramOrd, 0, Filename, 0, 1, 0, "宋体", nFontSize, 0, 0, 0, nFontColor, nStunt, nRunSpeet, nShowTime, 0, 0)
Label5.Caption = CStr(a)

End Sub

Private Sub Command6_Click()
On Error GoTo Error

    If (m_bSendBusy = False) Then
        m_bSendBusy = True
       a = -1
        iScreenNo = Val(Me.ScreenNO.Text)
       iSendMode = Me.sendMode.ListIndex
       
       a = SendScreenInfo(iScreenNo, 41456, 0)
        Label6.Caption = CStr(a)
        m_bSendBusy = False
    End If
Error:
    If Err Then
        MsgBox Err.Description
    End If
End Sub

Private Sub Command7_Click()
On Error GoTo Error

    If (m_bSendBusy = False) Then
        m_bSendBusy = True
        a = -1
         iScreenNo = Val(Me.ScreenNO.Text)
        iSendMode = Me.sendMode.ListIndex
        a = SendScreenInfo(iScreenNo, 41471, 0)
        Label7.Caption = CStr(a)
        m_bSendBusy = False
    End If
Error:
    If Err Then
        MsgBox Err.Description
    End If
End Sub


Private Sub Command8_Click()
'dlg.Filename = ""
'dlg.Filter = "文本文件(*.txt)|*.txt"
'dlg.ShowOpen
'If dlg.Filename <> "" Then Text1.Text = dlg.Filename
CommonDialog1.DialogTitle = " "
CommonDialog1.InitDir = "c:\"
CommonDialog1.Filter = "文本文件(*.txt)|*.txt;"
CommonDialog1.Filename = ""
CommonDialog1.ShowOpen
If CommonDialog1.Filename <> "" Then Text1.Text = CommonDialog1.Filename
'Shell CommonDialog1.Filename

End Sub

Private Sub Command9_Click()
Dim Text As String


Text = "123456"



    
   a = -1
   a = AddScreenProgramAreaBmpTextText(iScreenNo, 0, 0, Text, 0, 1, 0, "宋体", 10, 0, 0, 0, 255, 0, 32, 10, 0, 0)
Label21.Caption = CStr(a)
End Sub

Private Sub Form_Load()
Dim i As Integer
For i = 1 To 15
    Me.pCom.AddItem ("COM" & i)
Next
pCom.ListIndex = 0
Me.ScreenType.ListIndex = 1
Me.PixelMode.ListIndex = 2
Me.DataDa.ListIndex = 0
Me.DataOE.ListIndex = 0
Me.RowOrder.ListIndex = 0

sendMode.ListIndex = 0
Me.pCom.ListIndex = 0
Me.pBaut.ListIndex = 0
Me.cFontColor.ListIndex = 0
Me.CStunt.ListIndex = 0

nScreen = 1
m_bSendBusy = False

End Sub

Private Sub Text2_Change(Index As Integer)

End Sub

