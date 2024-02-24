# PS
여러가지 PS코드들과 과정들입니다.

###소마 15기 3번 문제 복기

코드는 이러하다
'''python
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
'''

문제내용은 처음에 
'''python
["f 1 2 3","d 3 10"]
'''
이런식으로 태그를 여러개 준다. 문자열 자체가 태그인데 태그 맨 앞의 소문자 알파벳은 그 태그의 id를 의미하고,
그 뒤의 여러개의 숫자들은 그 태그가 가진 class가 된다. 태그끼리 id는 겹치지 않지만 class는 겹칠 수 있고 
아예 없을 수도 있다고 제한사항이 있었다. 또한 태그들은 각각 폰트의 크기도 정해져 있는데, 명령으로 수정되기
전에는 전부 16으로 맞추라고 했다. 이렇게 태그를 입력하고 나서는
'''python
[".3 6","#.f 99",".3 12"]
'''
이렇게 명령을 여러개 준다. 명령마다 처음부분이 다르게 생겼는데 처음이 .(숫자)꼴이면 class로, #(알파벳)꼴이면
id로 태그를 찾아서 뒤에 있는 크기로 폰트를 바꿔줘야 한다. 단, 만약 어떤 태그가 이미 id를 통해 수정이 되었다면
그 태그는 class로는 수정하지 못하고 그 후의 명령 중 다시 id를 통한 명령으로만 수정할 수 있다.

class는 여러 태그를 지정가능하고 id는 고유하다고 해서 우선 각 id별로 폰트크기를 16으로 초기화한 font딕셔너리를
만들었고, 동시에 나중에 명령에 따라 이미 id로 수정되었는지 여부를 확인할 idcheck딕셔너리를 만들었다.
cl딕셔너리는 숫자 하나당 여러개의 태그를 지정해야 하므로 class-id리스트 쌍으로 만들었다.

명령을 저장한 commands리스트를 돌면서 처음부분에 따라 class형 명령이면 idcheck여부를 전부 확인해서 바꿔주고,
아니라면 그냥 바꿔주고 idcheck여부는 1로 바꾼다.(어차피 id끼리는 상관이 없기에)
KeyError가 왜 발생했나 생각을 해보니 처음에 cl딕셔너리에 숫자-문자리스트 쌍을 넣어야 했는데 반대로 하다가
시간을 다 잡아먹어서 머리가 안돌아가게 된 것 같다. 

실제 입력은 함수에 달린 매개변수형태로 줬기에 대충 문제를 되살려보면서 입력 형식을 조금 바꿨다. 골드 3정도 되었는데
아직 멀었나보다.