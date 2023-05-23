local cmp = require('cmp')

cmp.setup({
	sources = {
		{ name = "luasnip" },
		{ name = "nvim_lsp" },
	},
	mapping = {
		['<C-n>'] = cmp.mapping.select_next_item(),
		['<C-e>'] = cmp.mapping.select_prev_item(),
		['<M-n>'] = cmp.mapping.scroll_docs(4),
		['<M-e>'] = cmp.mapping.scroll_docs(-4),
		['<C-Space>'] = cmp.mapping.abort(),
		["<CR>"] = cmp.mapping({
			   i = function(fallback)
				 if cmp.visible() and cmp.get_active_entry() then
				   cmp.confirm({ behavior = cmp.ConfirmBehavior.Replace, select = false })
				 else
				   fallback()
				 end
			   end,
			   s = cmp.mapping.confirm({ select = true }),
			   c = cmp.mapping.confirm({ behavior = cmp.ConfirmBehavior.Replace, select = true }),
			 }),
	},
	snippet = {
		expand = function(args)
			local luasnip = require('luasnip')
			if not luasnip then
				return
			end
			luasnip.lsp_expand(args.body)
		end,
	},
})

