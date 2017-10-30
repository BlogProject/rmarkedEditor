import Vue from 'vue'
import App from './App.vue'
import "rmarked/css/github-markdown.css"
import "katex/dist/katex.min.css"
import "highlight.js/styles/tomorrow-night-blue.css"
import  'codemirror/lib/codemirror.css'

new Vue({
  el: '#app',
  render: h => h(App)
})
