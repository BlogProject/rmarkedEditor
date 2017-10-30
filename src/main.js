import Vue from 'vue'
import App from './App.vue'
import MyEditor from '../index.js'
import  'codemirror/lib/codemirror.css'
import "./css/simplemde.css"
import "rmarked/css/github-markdown.css"
import "katex/dist/katex.min.css"
import "highlight.js/styles/tomorrow-night-blue.css"

Vue.use(MyEditor)

new Vue({
  el: '#app',
  render: function(h){
    return h(App)
  }
})
