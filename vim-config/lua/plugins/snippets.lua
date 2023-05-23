local ls = require("luasnip")

local snip = ls.snippet
local func = ls.function_node

ls.setup({
	history = true,
	update_events = "TextChanged,TextChangedI",
	delete_check_events = "TextChanged",
	store_selection_keys = "<Tab>",
})

local load_file = function(file_name)
	local fn = function()
		local full_file_name = vim.env.HOME..'/.config/nvim/templates/'..file_name
		local ret = {}
		for line in io.lines(full_file_name) do
			table.insert(ret, line)
		end
		return ret
	end
	return fn
end

local template_snippet = function(file_type, trigger, file_name)
	ls.add_snippets(file_type, {
		snip({
			trig = trigger,
		}, {
			func(load_file(file_name), {}),
		}),
	})
end

template_snippet('cpp', 'template', 'template.cpp')
template_snippet('cpp', 'binary_search', 'binary_search.cpp')
template_snippet('cpp', 'segtree', 'data_structures/segtree.cpp')
template_snippet('cpp', 'mint', 'math/mint.cpp')
