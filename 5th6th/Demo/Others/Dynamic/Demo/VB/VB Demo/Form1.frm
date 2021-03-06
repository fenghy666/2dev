VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5745
   ClientLeft      =   60
   ClientTop       =   405
   ClientWidth     =   12165
   LinkTopic       =   "Form1"
   ScaleHeight     =   5745
   ScaleWidth      =   12165
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command9 
      Caption         =   "Delete DynamicArea"
      Height          =   735
      Left            =   5400
      TabIndex        =   19
      Top             =   4200
      Width           =   1575
   End
   Begin VB.CommandButton Command8 
      Caption         =   "Send Command Info"
      Height          =   735
      Left            =   2280
      TabIndex        =   17
      Top             =   4200
      Width           =   1455
   End
   Begin VB.CommandButton Command7 
      Caption         =   "Delete DynamicArea File"
      Height          =   855
      Left            =   5400
      TabIndex        =   14
      Top             =   3120
      Width           =   1575
   End
   Begin VB.CommandButton Command6 
      Caption         =   "Add DynamicArea File"
      Height          =   735
      Left            =   2280
      TabIndex        =   12
      Top             =   3240
      Width           =   1575
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Add Dynamic Area"
      Height          =   735
      Left            =   2280
      TabIndex        =   9
      Top             =   2280
      Width           =   1455
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Delete Screen"
      Height          =   735
      Left            =   5400
      TabIndex        =   6
      Top             =   1200
      Width           =   1575
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Add Screen"
      Height          =   735
      Left            =   2280
      TabIndex        =   4
      Top             =   1200
      Width           =   1455
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Initialize"
      Height          =   855
      Left            =   2280
      TabIndex        =   1
      Top             =   120
      Width           =   1455
   End
   Begin VB.Label Label13 
      Caption         =   "Label13"
      Height          =   255
      Left            =   7440
      TabIndex        =   20
      Top             =   4320
      Width           =   615
   End
   Begin VB.Label Label12 
      Caption         =   "Label12"
      Height          =   375
      Left            =   4200
      TabIndex        =   18
      Top             =   4320
      Width           =   855
   End
   Begin VB.Label Label11 
      Caption         =   "第五步："
      Height          =   255
      Left            =   1200
      TabIndex        =   16
      Top             =   4320
      Width           =   735
   End
   Begin VB.Label Label10 
      Caption         =   "Label10"
      Height          =   255
      Left            =   7440
      TabIndex        =   15
      Top             =   3240
      Width           =   615
   End
   Begin VB.Label Label9 
      Caption         =   "Label9"
      Height          =   375
      Left            =   4200
      TabIndex        =   13
      Top             =   3360
      Width           =   615
   End
   Begin VB.Label Label8 
      Caption         =   "第四步："
      Height          =   375
      Left            =   1200
      TabIndex        =   11
      Top             =   3360
      Width           =   735
   End
   Begin VB.Label Label7 
      Caption         =   "Label7"
      Height          =   255
      Left            =   4200
      TabIndex        =   10
      Top             =   2400
      Width           =   735
   End
   Begin VB.Label Label6 
      Caption         =   "第三步："
      Height          =   255
      Left            =   1200
      TabIndex        =   8
      Top             =   2400
      Width           =   855
   End
   Begin VB.Label Label5 
      Caption         =   "Label5"
      Height          =   375
      Left            =   7440
      TabIndex        =   7
      Top             =   1320
      Width           =   615
   End
   Begin VB.Label Label4 
      Caption         =   "Label4"
      Height          =   375
      Left            =   4200
      TabIndex        =   5
      Top             =   1320
      Width           =   615
   End
   Begin VB.Label Label3 
      Caption         =   "第二步："
      Height          =   375
      Left            =   1200
      TabIndex        =   3
      Top             =   1200
      Width           =   735
   End
   Begin VB.Label Label2 
      Caption         =   "Label2"
      Height          =   255
      Left            =   4200
      TabIndex        =   2
      Top             =   360
      Width           =   735
   End
   Begin VB.Label Label1 
      Caption         =   "第一步："
      Height          =   255
      Left            =   1200
      TabIndex        =   0
      Top             =   360
      Width           =   855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'控制卡型号
Const CONTROLLER_BX_5E1 = &H154
Const CONTROLLER_BX_5E2 = &H254
Const CONTROLLER_BX_5E3 = &H354
Const CONTROLLER_BX_5Q0P = &H1056
Const CONTROLLER_BX_5Q1P = &H1156
Const CONTROLLER_BX_5Q2P = &H1256
Const CONTROLLER_BX_6Q1 = &H166
Const CONTROLLER_BX_6Q2 = &H266
Const CONTROLLER_BX_6Q2L = &H466
Const CONTROLLER_BX_6Q3 = &H366
Const CONTROLLER_BX_6Q3L = &H566

'通讯模式
Const SEND_MODE_SERIALPORT = 0
Const SEND_MODE_NETWORK = 2
Const SEND_MODE_Server_2G = 5
Const SEND_MODE_Server_3G = 6
Const SEND_MODE_SAVEFILE = 7

Private Sub Command1_Click()
    Dim nResult As Integer
    nResult = Initialize()
    Label2.Caption = CStr(nResult)
End Sub

Private Sub Command2_Click()
    Dim nControlType, nScreenNo, nSendMode, nWidth, nHeight, nScreenType, nPixelMode, nBaud, nSocketPort, nStaticIpMode, nServerMode, nServerPort, nResult As Integer
    Dim pCom, pSocketIP, pBarcode, pNetworkID, pServerIP, pServerAccessUser, pServerAccessPassword, pCommandDataFile As String
    
    nControlType = CONTROLLER_BX_6Q2L
    nScreenNo = 1
    nSendMode = SEND_MODE_NETWORK
    nWidth = 128
    nHeight = 32
    nScreenType = 2
    nPixelMode = 2
    pCom = ""
    nBaud = 57600
    pSocketIP = "192.168.10.147"
    nSocketPort = 5005
    nStaticIpMode = 0
    nServerMode = 0
    pBarcode = ""
    pNetworkID = ""
    pServerIP = ""
    nServerPort = 5005
    pServerAccessUser = ""
    pServerAccessPassword = ""
    pCommandDataFile = ""
    
    nResult = AddScreen_Dynamic(nControlType, nScreenNo, nSendMode, nWidth, nHeight, nScreenType, nPixelMode, pCom, nBaud, pSocketIP, nSocketPort, _
                                nStaticIpMode, nServerMode, pBarcode, pNetworkID, pServerIP, nServerPort, pServerAccessUser, pServerAccessPassword, pCommandDataFile)
    
    Label4.Caption = CStr(nResult)
End Sub

Private Sub Command3_Click()
    Dim nScreenNo, nResult As Integer
    
    nScreenNo = 1
    
    nResult = DeleteScreen_Dynamic(nScreenNo)
    
    Label5.Caption = CStr(nResult)
End Sub

Private Sub Command4_Click()
    Dim nScreenNo, nDYAreaID, nRunMode, nTimeOut, nAllProRelate, nPlayImmediately, nAreaX, nAreaY, nAreaWidth, nAreaHeight, nAreaFMode, nAreaFLine, nAreaFColor, nAreaFStunt, nAreaFRunSpeed, nAreaFMoveStep, nResult As Integer
    Dim pProRelateList As String
    
    nScreenNo = 1
    nDYAreaID = 0
    nRunMode = 0
    nTimeOut = 10
    nAllProRelate = 0
    pProRelateList = ""
    nPlayImmediately = 1
    nAreaX = 0
    nAreaY = 0
    nAreaWidth = 128
    nAreaHeight = 32
    nAreaFMode = 255
    nAreaFLine = 0
    nAreaFColor = 255
    nAreaFStunt = 1
    nAreaFRunSpeed = 6
    nAreaFMoveStep = 1
    
    nResult = AddScreenDynamicArea(nScreenNo, nDYAreaID, nRunMode, nTimeOut, nAllProRelate, pProRelateList, nPlayImmediately, nAreaX, nAreaY, _
                                   nAreaWidth, nAreaHeight, nAreaFMode, nAreaFLine, nAreaFColor, nAreaFStunt, nAreaFRunSpeed, nAreaFMoveStep)
                                   
    Label7.Caption = CStr(nResult)
    
End Sub

    
Private Sub Command6_Click()
    Dim nScreenNo, nDYAreaID, nShowSingle, nAlignment, nFontSize, nBold, nFontColor, nStunt, nRunSpeed, nShowTime, nResult As Integer
    Dim pFileName, pFontName As String
    
    nScreenNo = 1
    nDYAreaID = 0
    pFileName = "Test.txt"
    nShowSingle = 0
    nAlignment = 0
    pFontName = "宋体"
    nFontSize = 8
    nBold = 0
    nFontColor = 65535
    nStunt = 1
    nRunSpeed = 2
    nShowTime = 6
    
    nResult = AddScreenDynamicAreaFile(nScreenNo, nDYAreaID, pFileName, nShowSingle, nAlignment, pFontName, nFontSize, nBold, nFontColor, nStunt, nRunSpeed, nShowTime)
    
    Label9.Caption = CStr(nResult)
    
End Sub

Private Sub Command7_Click()
    Dim nScreenNo, nDYAreaID, nFileOrd, nResult As Integer
    
    nScreenNo = 1
    nDYAreaID = 0
    nFileOrd = 0
    
    nResult = DeleteScreenDynamicAreaFile(nScreenNo, nDYAreaID, nFileOrd)
    
    Label10.Caption = CStr(nResult)
    
End Sub

Private Sub Command8_Click()
    Dim nScreenNo, nDYAreaID, nResult As Integer
    
    nScreenNo = 1
    nDYAreaID = 0
    pDYAreaIDList = 0
    
    nResult = SendDynamicAreasInfoCommand(nScreenNo, nDYAreaID, pDYAreaIDList)
    
    Label12.Caption = CStr(nResult)
End Sub

Private Sub Command9_Click()
    Dim nScreenNo, nDYAreaID, nResult As Integer
    Dim pDYAreaIDList As String
    
    nScreenNo = 1
    nDYAreaID = 1
    pDYAreaIDList = ""
    
    nResult = SendDeleteDynamicAreasCommand(nScreenNo, nDYAreaID, pDYAreaIDList)
    Label13.Caption = CStr(nResult)
End Sub
