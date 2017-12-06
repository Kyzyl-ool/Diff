graph
[
	node
	[
		id 140373141759904
		label "PLUS"
	]

	node
	[
		id 140373141759952
		label "MULTIPLY"
	]

	node
	[
		id 140373141760000
		label "5"
	]

	edge
	[
		source 140373141759952
		target 140373141760000
		label "left"
	]
	node
	[
		id 140373141760080
		label "x"
	]

	edge
	[
		source 140373141759952
		target 140373141760080
		label "right"
	]
	edge
	[
		source 140373141759904
		target 140373141759952
		label "left"
	]
	node
	[
		id 140373141760128
		label "MULTIPLY"
	]

	node
	[
		id 140373141760176
		label "3"
	]

	edge
	[
		source 140373141760128
		target 140373141760176
		label "left"
	]
	node
	[
		id 140373141760224
		label "x"
	]

	edge
	[
		source 140373141760128
		target 140373141760224
		label "right"
	]
	edge
	[
		source 140373141759904
		target 140373141760128
		label "right"
	]
]
