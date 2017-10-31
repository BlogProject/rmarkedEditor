<template>
  <div id="app">
    <h1>
      markdownEditor
    </h1>
    <markdown-editor
      v-model="input"
      :configs="configs"
      >
    </markdown-editor>

    <h1>
      codeEditor
    </h1>

    <code-editor
      v-model="code"
      :options="codeOpts">
    </code-editor>
  </div>
</template>

<script>
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
      },
      configs:{
        debounce:true,
        debounce_time:3000
      }
    }
  },
  mounted(){
    let self = this
    $.get("test.md").then(function(data){
      console.log("test.md loaded success!")
      self.input= data
    })
    $.get("test.cpp").then(function(data){
      console.log("test.cpp loaded success!")
      self.code= data
    })

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

.markdown-body pre.hljs {
  background:#002451;
}


</style>
