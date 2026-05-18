def is_var(x):
    return x[0].islower()

def unify(x,y):
    if x==y:
        return {}
    if is_var(x):
        return {x:y}
    if is_var(y):
        return {y:x}
    return None

def substitute(clause, subs):
    result = []
    for literal in clause:
        neg = literal.startswith('~')
        core = literal[1:] if neg else literal

        pred,args = core.split('(')
        args = args.strip(')').split(',')
        new_args = [subs.get(arg,arg) for arg in args]
        new_literal = (('~' if neg else '')+ pred+ '('+','.join(new_args)+')')
        result.append(new_literal)
    return result

def resolve(ci,cj):
    resolvents = []
    for li in ci:
        for lj in cj:
            if(li.startswith('~') and not lj.startswith('~') and li[1:].split('(')[0]==lj.split('(')[0]):
                xi = li[1:]
                xj = lj
            elif(lj.startswith('~') and not li.startswith('~') and lj[1:].split('(')[0]==li.split('(')[0]):
                xi = li
                xj = lj[1:]
            else:
                continue

            ai = xi.split('(')[1].strip(')').split(',')
            aj = xj.split('(')[1].strip(')').split(',')

            if len(ai)!=len(aj):
                continue

            subs = {}
            for a,b in zip(ai,aj):
                result = unify(a,b)
                if result is None:
                    break
                subs.update(result)
            else:
                new_clause = ([l for l in ci if l!=li] + [l for l in cj if l!=lj])
                new_clause = substitute(new_clause, subs)
                resolvents.append(new_clause)
    return resolvents

def resolution(clauses):
    while True:
        new = []
        n = len(clauses)
        for i in range(n):
            for j in range(i+1,n):
                resolvent_list = resolve(clauses[i], clauses[j])
                for resolvent in resolvent_list:
                    if not resolvent:
                        return True
                    if resolvent not in new and resolvent not in clauses:
                        new.append(resolvent)
        if not new:
            return False
        clauses.extend(new)


kb = [
    ['~Human(x)', 'Mortal(x)'],
    ['Human(Socrates)'],
    ['~Mortal(Socrates)']
]

if resolution(kb):
    print("Query is Entailed: Socrates is a mortal")
else:
    print("Query is not entailed")
