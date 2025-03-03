st =input()

ans = ""

i=0
while i<len(st):
    if st[i] == '.':
        ans += '.'
        i+=1
    elif st[i:i+4] == "XXXX":
        ans+="AAAA"
        i+=4
    elif st[i:i+2] == "XX":
        ans+="BB"
        i+=2
    else:
        ans = ""
        break

if (not ans): print(-1)
else: print(ans)