
BindGameObject("Player") 
BeginCommandGroup("Player","Parallel")

    MoveWithTime(-6,9,30,0)
    RotateWithTime(0,90,0,0);

    WaitForSeconds(2.5)
    
    FollowCurveWithTime(5).AddPoint(-5,9,30,  10,9,0).AddPoint(40,9,30,  30,9,60).EaseIn("Sine",2).EaseOut("Sine",2)

    --MoveWithTime(15,20,30,5).EaseIn("Bounce", 2).EaseOut("Bounce",2);
    --RotateWithTime(-45,90,0,2).EaseIn("Bounce",2)


EndCommandGroup("Player")


BeginCommandGroup("CarSpawn","Serial")

    SpawnCar("Car1",0)
    BindGameObject("Car1") 
    MoveWithTime(15, 9, 30,0)
    RotateWithTime(-90,90,0,0);
    RotateWithTime(-90,-90,0,5);


    SpawnCar("Car2",0)
    BindGameObject("Car2") 
    MoveWithTime(30, 9, 30,0)

EndCommandGroup("CarSpawn")
