
BindGameObject("Player") 
BeginCommandGroup("Player","Parallel",3);

    WaitForSeconds(2.5)
    MoveToPositionWithTime(0,5,0,2.5)

EndCommandGroup()