from collections import deque

# create deque
dq = deque()

# add elements to the front
dq.appendleft(1)
dq.appendleft(2)

# add elements to rear
dq.append(3)
dq.append(4)

# remove elements from front
print(dq.popleft())

# remove elements from rear
print(dq.pop())

# check if deque is empty
print(dq.is_empty())
