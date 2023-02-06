local function map(m, k, v)
	vim.keymap.set(m, k, v, { silent = true })
end

vim.cmd [[nnoremap <space>t :-1read $HOME/.config/nvim/templates/template.cpp<CR>/{<CR>o]]
