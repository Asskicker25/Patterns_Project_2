
BindGameObject("Player") 
BeginCommandGroup("Player","Parallel",3);

    MoveWithTime(-6,9,30,0)
    RotateWithTime(0,90,0,0);

    WaitForSeconds(2.5)
    
    MoveWithTime(15,20,30,5).EaseIn("Bounce", 2).EaseOut("Bounce",2);
    RotateWithTime(-45,90,0,2).EaseIn("Bounce",2)


EndCommandGroup()