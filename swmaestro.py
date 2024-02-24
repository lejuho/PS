def sol():
    font=dict()
    cl=dict()
    idcheck=dict()
    n=int(input())
    tags=[input() for i in range(n)]
    for tag in tags:
        temp=list(tag.split())
        alpha=temp[0]
        for num in temp[1:]:
            if num not in cl:
                cl[num]=list(alpha)
            else:
                cl[num].append(alpha)
        font[alpha]=16
        idcheck[alpha]=0
    print(font)
    
    commands=[]
    t=int(input())
    for i in range(t):
        commands.append(input())
    
    for com in commands:
        temp=list(com.split())
        isid=temp[0]
        change=int(temp[1])
        if isid[0]=="#":
            font[isid[1]]=change
            idcheck[isid[1]]=1
        else:
            for alp in cl[isid[1]]:
                if idcheck[alp]==0:
                    font[alp]=change
        
    print(font,cl)
sol()