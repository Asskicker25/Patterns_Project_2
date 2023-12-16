
BindGameObject("Camera") 
BeginCommandGroup("InitialCameraMove","Parallel")

    MoveWithTime(290,125,-36,0)
    RotateWithTime(-23,-230,0,0);

    WaitForSeconds(1)

    RotateWithTime(-36,-271,0,1).EaseIn("Sine",1);
    
    FollowCurveWithTime(1).AddPoint(290,125,-36,  0,0,0)
    .AddPoint(222,140,104,  0,0,0)
    .AddPoint(157,73,332, 0,0,0).AddPoint(158,31,347,  0,0,0).EaseIn("Sine",2)
    .EaseOut("Circ",2)

EndCommandGroup("InitialCameraMove")


BindGameObject("Camera") 
BeginCommandGroup("CarFollow","Serial")
    
    WaitForSeconds(4)
    FollowObject("PatrolCar1",19).SetFollowDistance(20).SetFollowOffset(0,10,0).SetMaxSpeed(0.01).SetAccelerationRange(30).SetAccelerationRange(60)

    WaitForSeconds(1)
    FollowObject("PatrolCar2",19).SetFollowDistance(20).SetFollowOffset(0,10,0).SetMaxSpeed(0.01).SetAccelerationRange(30).SetAccelerationRange(60)
    --LookAt("PatrolCar1",15)

EndCommandGroup("InitialCameraMove")

