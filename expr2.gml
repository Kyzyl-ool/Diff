graph
[
	node
	[
		id 140473830221904
		label "MULTIPLY"
	]

	node
	[
		id 140473830221952
		label "5"
	]

	edge
	[
		source 140473830221904
		target 140473830221952
		label "left"
	]
	node
	[
		id 140473830222000
		label "POWER"
	]

	node
	[
		id 140473830222048
		label "x"
	]

	edge
	[
		source 140473830222000
		target 140473830222048
		label "left"
	]
	node
	[
		id 140473830222096
		label "0"
	]

	edge
	[
		source 140473830222000
		target 140473830222096
		label "right"
	]
	edge
	[
		source 140473830221904
		target 140473830222000
		label "right"
	]
]
