
BindGameObject("Camera") 
BeginCommandGroup("InitialCameraMove","Parallel")

    MoveWithTime(290,125,-36,0)
    RotateWithTime(-23,-230,0,0);

    WaitForSeconds(0.1)

    RotateWithTime(-36,-271,0,1).EaseIn("Sine",1);
    
    FollowCurveWithTime(1).AddPoint(290,125,-36,  290,125,-36)
    .AddPoint(222,140,104,  222,140,104)
    .AddPoint(157,73,332, 157,73,332).AddPoint(158,31,347,  158,31,347).EaseIn("Sine",2)
    .EaseOut("Circ",2)
    
EndCommandGroup("InitialCameraMove")