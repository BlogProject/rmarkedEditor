<template>
  <div id="app">
    <markdown-editor
      v-model="input"
      >
    </markdown-editor>
    {{ input}}
    <code-editor
      v-model="code"
      :options="codeOpts">
    </code-editor>
    {{ code }}
  </div>
</template>

<script>
var rmarked  = require("rmarked")()
import markdownEditor from "./rsimplemde.vue"
import codeEditor from './codeEditor.vue'
export default {
  name: 'app',
  data () {
    return {
      input:"# hello",
      last:null,
      code:"const a  = 10",
      editorOptions:{
        tabSize:4,
        lineNumbers:true,
        mode:"markdown"
      },
      codeOpts:{
        tabSize:4,
        lineNumbers:true
      }

    }
  },
  components:{
    markdownEditor,
    codeEditor
  },
  mounted(){
  },
  methods:{
    update(e){
      let self = this
      clearTimeout(self.last)
      self.last = setTimeout(function(){ 
        self.input = e.target.value 
      },500)

    }
  },
  computed:{
    compiledMarked(){
      let self = this
      return rmarked(self.input)
    }
  }
}
</script>

<style>
html,body,#app {
  margin:0;
  height:100%;
  color:#333;
}
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  margin-top: 20px;
}

</style>
