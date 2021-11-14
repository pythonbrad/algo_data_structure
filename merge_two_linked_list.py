
class Node:
	def __init__(self, val, next=None):
		self.val = val
		self.next = next

class Solution:
	def mergeTwoLists(self, a, b):
		if a == None or b == None:
			if a:
				return a
			elif b:
				return b
			else:
				return None
		elif a.val < b.val:
			c = Node(a.val)
			c.next = self.mergeTwoLists(a.next, b)
		else:
			c = Node(b.val)
			c.next = self.mergeTwoLists(b.next, a)
		return c

a = Node(1)
a.next = Node(3)
a.next.next = Node(5)


b = Node(2)
b.next = Node(4)
b.next.next = Node(6)

c = Solution().mergeTwoLists(a, b)

while c:
	print(c.val)
	c = c.next
