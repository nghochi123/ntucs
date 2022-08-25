def collect_rainwater(s):
    # base case
    if (s[0]=='H' and s[1]!='_') or (s[len(s)-1]=='H' and s[len(s)-2]!='_'):
        return -1
    tanks = {}
    for i in range(1,len(s)):
        if s[i]=='H':
            if i==len(s)-1:
                tanks[i] = i-1
            elif (s[i+1] =='_' or s[i-1]=='_'):
                if len(tanks) == 0:
                    if s[i+1] =='_':
                        tanks[i] = i+1
                    else:
                        tanks[i] = i-1
                else:
                    if s[i-1]=='_':
    #                     if i-1 in tanks.values():
                        tanks[i] = i-1
                    else:
                        tanks[i] = i+1
            else: 
                return  -1       
    print(tanks)
    return len(set(tanks.values()))

s = '_H_HH_H_'
tanks = collect_rainwater(s)
s = '_HH_HH_HH'
tanks = collect_rainwater(s)
s = '_HH_HH_HH_H'
tanks = collect_rainwater(s)
s = 'HH_HH_HH_H'
tanks = collect_rainwater(s)
tanks