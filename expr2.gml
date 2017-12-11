graph
[
	node
	[
		id 140328641232896
		label "DIVIDE"
	]

	node
	[
		id 140328641232944
		label "MINUS"
	]

	node
	[
		id 140328641233040
		label "MULTIPLY"
	]

	node
	[
		id 140328641233424
		label "MULTIPLY"
	]

	node
	[
		id 140328641233568
		label "COS"
	]

	node
	[
		id 140328641233664
		label "x"
	]

	edge
	[
		source 140328641233568
		target 140328641233664
		label "left"
	]
	edge
	[
		source 140328641233424
		target 140328641233568
		label "left"
	]
	node
	[
		id 140328641233712
		label "1"
	]

	edge
	[
		source 140328641233424
		target 140328641233712
		label "right"
	]
	edge
	[
		source 140328641233040
		target 140328641233424
		label "left"
	]
	node
	[
		id 140328641233760
		label "COS"
	]

	node
	[
		id 140328641233808
		label "x"
	]

	edge
	[
		source 140328641233760
		target 140328641233808
		label "left"
	]
	edge
	[
		source 140328641233040
		target 140328641233760
		label "right"
	]
	edge
	[
		source 140328641232944
		target 140328641233040
		label "left"
	]
	node
	[
		id 140328641233088
		label "MULTIPLY"
	]

	node
	[
		id 140328641233952
		label "SIN"
	]

	node
	[
		id 140328641234000
		label "x"
	]

	edge
	[
		source 140328641233952
		target 140328641234000
		label "left"
	]
	edge
	[
		source 140328641233088
		target 140328641233952
		label "left"
	]
	node
	[
		id 140328641234048
		label "MULTIPLY"
	]

	node
	[
		id 140328641234192
		label "MULTIPLY"
	]

	node
	[
		id 140328641234240
		label "-1"
	]

	edge
	[
		source 140328641234192
		target 140328641234240
		label "left"
	]
	node
	[
		id 140328641234288
		label "SIN"
	]

	node
	[
		id 140328641234384
		label "x"
	]

	edge
	[
		source 140328641234288
		target 140328641234384
		label "left"
	]
	edge
	[
		source 140328641234192
		target 140328641234288
		label "right"
	]
	edge
	[
		source 140328641234048
		target 140328641234192
		label "left"
	]
	node
	[
		id 140328641234432
		label "1"
	]

	edge
	[
		source 140328641234048
		target 140328641234432
		label "right"
	]
	edge
	[
		source 140328641233088
		target 140328641234048
		label "right"
	]
	edge
	[
		source 140328641232944
		target 140328641233088
		label "right"
	]
	edge
	[
		source 140328641232896
		target 140328641232944
		label "left"
	]
	node
	[
		id 140328641232992
		label "POWER"
	]

	node
	[
		id 140328641233184
		label "COS"
	]

	node
	[
		id 140328641233232
		label "x"
	]

	edge
	[
		source 140328641233184
		target 140328641233232
		label "left"
	]
	edge
	[
		source 140328641232992
		target 140328641233184
		label "left"
	]
	node
	[
		id 140328641233280
		label "2"
	]

	edge
	[
		source 140328641232992
		target 140328641233280
		label "right"
	]
	edge
	[
		source 140328641232896
		target 140328641232992
		label "right"
	]
]
