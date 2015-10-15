Attribute VB_Name = "Module1"
Option Explicit

Sub ChangeTab(SSTab As SSTab)
    Dim ctrl As Control, TabIndex As Long
    
    TabIndex = 99999          ' A very high value.
    
    On Error Resume Next

    For Each ctrl In SSTab.Parent.Controls
        If ctrl.Container Is SSTab Then
            If ctrl.Left < -10000 Then
                ctrl.Enabled = False
            Else
                ctrl.Enabled = True
                If ctrl.TabIndex >= TabIndex Then
                    ' this control comes after our best candidate or
                    ' ctrl doesn't support the TabIndex property.
                Else
                    ' This is the best candidate to get the focus (so far).
                    TabIndex = ctrl.TabIndex
                    ' (Next statement may fail with a few controls (e.g. Labels)
                    ctrl.SetFocus
                End If
            End If
        End If
    Next
End Sub


