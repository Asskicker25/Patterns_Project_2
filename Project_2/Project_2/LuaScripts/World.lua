
BindGameObject("Player") 
BeginCommandGroup("Player","Parallel",3);

    MoveWithTime(-6,9,30,0)
    RotateWithTime(0,90,0,0);

    WaitForSeconds(2.5)
    
    MoveWithTime(15,20,30,5).EaseIn("Bounce", 2).EaseOut("Sine",2);
    RotateWithTime(-45,90,0,2).EaseIn("Bounce",2)

    -- SetEaseOutTime("Sine", 2);
    --MoveWithSpeed(30,9,30,1);
    -- SetEaseInDistance("Sine", 2); SetEaseOutDistance("Sine", 2);

EndCommandGroup()