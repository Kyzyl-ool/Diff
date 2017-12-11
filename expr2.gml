graph
[
	node
	[
		id 140374887628800
		label "MULTIPLY"
	]

	node
	[
		id 140374887628944
		label "MULTIPLY"
	]

	node
	[
		id 140374887629040
		label "3"
	]

	edge
	[
		source 140374887628944
		target 140374887629040
		label "left"
	]
	node
	[
		id 140374887629088
		label "POWER"
	]

	node
	[
		id 140374887629184
		label "MINUS"
	]

	node
	[
		id 140374887629232
		label "x"
	]

	edge
	[
		source 140374887629184
		target 140374887629232
		label "left"
	]
	node
	[
		id 140374887629280
		label "2"
	]

	edge
	[
		source 140374887629184
		target 140374887629280
		label "right"
	]
	edge
	[
		source 140374887629088
		target 140374887629184
		label "left"
	]
	node
	[
		id 140374887629328
		label "MINUS"
	]

	node
	[
		id 140374887629424
		label "3"
	]

	edge
	[
		source 140374887629328
		target 140374887629424
		label "left"
	]
	node
	[
		id 140374887629472
		label "1"
	]

	edge
	[
		source 140374887629328
		target 140374887629472
		label "right"
	]
	edge
	[
		source 140374887629088
		target 140374887629328
		label "right"
	]
	edge
	[
		source 140374887628944
		target 140374887629088
		label "right"
	]
	edge
	[
		source 140374887628800
		target 140374887628944
		label "left"
	]
	node
	[
		id 140374887629520
		label "MINUS"
	]

	node
	[
		id 140374887629664
		label "1"
	]

	edge
	[
		source 140374887629520
		target 140374887629664
		label "left"
	]
	node
	[
		id 140374887629712
		label "0"
	]

	edge
	[
		source 140374887629520
		target 140374887629712
		label "right"
	]
	edge
	[
		source 140374887628800
		target 140374887629520
		label "right"
	]
]
