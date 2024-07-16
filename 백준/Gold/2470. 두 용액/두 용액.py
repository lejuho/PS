from sys import stdin
input = stdin.readline

def sol():
    n=int(input())
    liquid=list(map(int,input().split()))
    liquid.sort()
    l=0
    r=n-1
    ansl=0
    ansr=0
    last=float("inf")
    while r>l:
        tmp=liquid[r]+liquid[l]
        if abs(tmp)<last:
            last=abs(tmp)
            ansr=r
            ansl=l
        if tmp==0:
            break
        if tmp<0:
            l+=1
        else:
            r-=1
    print(liquid[ansl],liquid[ansr])
sol()